#include "igraph.h"
#include "vector"

void Igraph::addEdge(int idA, int idB){
    graph[idA].push_back(idB);
}

int Igraph::largestDegree(vector<int>& words){
    int max = 0;
    // vector<int> words;
    for(int i = 0; i < wl.size(); i++){
        
        // cout << graph[i].size() << endl;
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
    //go through every word and change every word on the (ascii 97 - 122)
    // maybe change for speed?

    for(int i = 0; i < wl.size(); i++){
        // string s = wl[i];
        for(int j = 0; j < wl[i].size(); j++){
            // cout << wl[i][j] << endl;
            int letter = wl[i][j];
            for(int a = 97; a <= 122; a++){
                string temp = wl[i];
                if(letter != a){
                    temp[j] = a;
                    // cout << temp << endl;

                    int c = checkWord(temp);
                    if(c != -1){
                        addEdge(i,c);
                        edges++;
                    }
                }
            }
        }
    }

    // for(int i = 0; i < wl.size(); i++){\
    //     for(int j = 0; j < wl.size(); j++){
            
    //         if(checkNeighbor(i,j)){
    //             // cout << i << " and " << j << " are neighbors" << endl;
    //             addEdge(i,j);
    //             // cout << "edge added" << endl;
    //         }
    //     
    // }
    
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
    //check if it is in the wordlist? -1 if don't exist

    return cWHelper(word, 0, wl.size() - 1);
}

int Igraph::cWHelper(string word, int beginning, int end){
    // cout << "beginning: " << beginning << "end: " << end << endl;
    if(beginning == end){
        if(word.compare(wl[end]) == 0) { //.equals?
            return end;
        }
        else{
            return -1;
        }
    }
    else {
        // cout << "not equal!" << endl;
        int middle = (beginning + end)/2;
        if(word.compare(wl[middle]) == 0){
            return middle;
        }
        else if(word.compare(wl[middle])<0){
            // cout << "earlier than current middle!" << endl;
            return cWHelper(word, beginning, middle);
        }
        else{
            // cout << "later than current middle!" << endl;
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
        cout << wl[*iter] << endl;
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
    // int d[wl.size()];
    // int pred[wl.size()];
    // int visited[wl.size()];
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
        // cout << getWord(curr) << endl;
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

// evict in create and whenever you put it in node map