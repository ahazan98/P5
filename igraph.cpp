
// @authors Alex Hazan and Brandon Ra


#include "igraph.h"
#include "vector"

void Igraph::addEdge(int idA, int idB){
    graph[idA].push_back(idB);
}

int Igraph::largestDegree(vector<int>& words){
    int max = 0;
    for(int i = 0; i < wl.size(); i++){
        
        if(graph[i].size() == max){
            words.push_back(i);
        }
        else if (graph[i].size() > max){
            max = graph[i].size();
            words.clear();
            words.push_back(i);
        }
    }
    return max;
}
void Igraph::makeGraph(){
    

    for(int i = 0; i < wl.size(); i++){
        for(int j = 0; j < wl[i].size(); j++){
            int letter = wl[i][j];
            for(int a = 97; a <= 122; a++){
                string temp = wl[i];
                if(letter != a){
                    temp[j] = a;
                    int c = checkWord(temp);
                    if(c != -1){
                        addEdge(i,c);
                        edges++;
                    }
                }
            }
        }
    }    
}

bool Igraph::checkNeighbor(int idA, int idB){
    if(idA == idB){
        return false;
    }

    string a = wl[idA];
    string b = wl[idB];
    int similarities = a.size();

    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            similarities --;
        }
        if(similarities < (a.size() -1)){
            return false;
        }
    }
    return true;

}

string Igraph::getWord(int id){
    return wl[id];
}

int Igraph::checkWord(string word){
    return cWHelper(word, 0, wl.size() - 1);
}

int Igraph::cWHelper(string word, int beginning, int end){
    if(beginning == end){
        if(word.compare(wl[end]) == 0) { 
            return end;
        }
        else{
            return -1;
        }
    }
    else {
        int middle = (beginning + end)/2;
        if(word.compare(wl[middle]) == 0){
            return middle;
        }
        else if(word.compare(wl[middle])<0){
            return cWHelper(word, beginning, middle);
        }
        else{
            return cWHelper(word,middle+1,end);
        }
    }
}

int Igraph::checkDegree(int id){
    return graph[id].size();
}


void Igraph::getNeighborhood(int id){
    vector<int> neighbors = graph[id];
    for(vector<int>::iterator iter = neighbors.begin(); iter != neighbors.end(); iter++){
        cout << setw(10) << wl[*iter] << endl;
    }
}
vector<int> Igraph::connectedComponent(int& maxComp){
    vector<int> visited(wl.size(),0);
    vector<int> d(wl.size(),0);
    vector<int> pred(wl.size(),-1);
    
    int numVisited = 0;
    vector<int> components;
    for(int i = 0; i < wl.size(); i++){
        if(visited[i] != 1){
            BFS(i, visited, d, pred, numVisited);
            components.push_back(numVisited);
            if(numVisited > maxComp){
                maxComp = numVisited;
            }
            numVisited = 0;
            continue;
        }
    }
    return components;
}
void Igraph::BFS(int id, vector<int>& visited, vector<int>& d,vector<int>& pred, int& numVisited){
    queue <int> q;

    visited[id] = 1;
    numVisited++;
    q.push(id);
    d[id] = 0;
    pred[id] = -1;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        vector<int> neighbors = graph[v];
        for(int w = 0; w < neighbors.size(); w++){
            if(visited[neighbors[w]] != 1){

                d[neighbors[w]] = d[v] + 1;
                pred[neighbors[w]] = v;
                visited[neighbors[w]] = 1;
                numVisited++;
                q.push(neighbors[w]);
            }
        }
    }
}

vector<int> Igraph::shortestPath(int startId, int endId){
    vector<int> visited(wl.size(),0);
    vector<int> d(wl.size(),0);
    vector<int> pred(wl.size(),-1);
    int numVisited;
    vector<int> path;

    BFS(startId, visited, d, pred, numVisited);
    if(visited[endId] == 0){
        cout << "There is no path from " << getWord(startId) << " to " << getWord(endId) << endl;
        path.push_back(-1);
        return path;
    }

    int curr = endId;
    while(curr != -1){
        path.push_back(curr);
        curr = pred[curr];
    }
    
    
    return path;   
}

int Igraph::getEccentricity(int id){
    vector<int> visited(wl.size(),0);
    vector<int> d(wl.size(),0);
    vector<int> pred(wl.size(),-1);
    int numVisited;
    BFS(id, visited, d, pred, numVisited);

    int ev = 0;

    for(int i = 0; i < d.size(); i++){
        if (d[i] > ev){
            ev = d[i];
        }
    }
    return ev;
}

