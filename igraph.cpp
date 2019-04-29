#include "igraph.h"
#include "vector"

void Igraph::addEdge(int idA, int idB){
    graph[idA].push_back(idB);
}

bool Igraph::checkWord(string word){
    //check if it is in the wordlist?
    return true;
}

int Igraph::checkDegree(int id){
    return graph[id].size();
}


void Igraph::checkNeighborhood(int id){
    vector<string> neighbors;
    for(vector<string>::iterator iter = neighbors.begin(); iter != neighbors.end(); iter++){
        cout << *iter << endl;
    }
}