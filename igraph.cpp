#include "igraph.h"
#include "vector"

void Igraph::addEdge(int idA, int idB){
    graph[idA].push_back(idB);

    // vector<int> edges = graph.at(idA);
    // cout << "hi" << endl;
    // edges.push_back(idB);
    
    // for(int i = 0; i < edges.size(); i ++){
    //     cout << edges[i]<< endl;
    // }
    // graph[idA] = edges;
}

void Igraph::makeGraph(){
    //go through every word and change every word on the (ascii 97 - 122)
    // maybe change for speed?

    for(int i = 0; i < wl.size(); i++){\
        for(int j = 0; j < wl.size(); j++){
            
            if(checkNeighbor(i,j)){
                // cout << i << " and " << j << " are neighbors" << endl;
                addEdge(i,j);
                // cout << "edge added" << endl;
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
    //check if it is in the wordlist? -1 if don't exist

    return cWHelper(word, 0, wl.size() - 1);
}

int Igraph::cWHelper(string word, int beginning, int end){
    cout << "beginning: " << beginning << "end: " << end << endl;
    if(beginning == end){
        if(word.compare(wl[end]) == 0) { //.equals?
            return end;
        }
        else{
            return -1;
        }
    }
    else {
        cout << "not equal!" << endl;
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
vector<int> Igraph::connectedComponent(){
    vector<int> visited(wl.size(),0);
    vector<int> d(wl.size(),0);
    vector<int> pred(wl.size(),0);
    
    vector<int> components;
    int numVisited = 0;
    int count = 0;
    for(int i = 0; i < wl.size(); i++){
        cout << "word id: " << i << endl;
        if(visited[i] != 1){
            cout << "starting " << count << "'s BFS" << endl;
            BFS(i, visited, d, pred, numVisited);
            cout << "BFS success" << endl;
            components.push_back(numVisited);
            cout << "component success" << endl;
            numVisited = 0;
            count++;
        }
        cout << "No need for BFS" << endl;
    }
    cout << "done with components" << endl;
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
                d[w] = d[v] + 1;
                pred[w] = v;
                visited[w] = 1;
                numVisited++;
                q.push(w);
            }
        }
    }


}