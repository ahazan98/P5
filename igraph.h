// @authors Alex Hazan and Brandon Ra


#ifndef igraph_h
#define igraph_h
#include <cstddef>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <cmath>
#include <cassert>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

class Igraph {

    public:
    Igraph(const vector<string>& w): wl(w) {
        for(int i = 0; i < wl.size(); i++){
            vertices = wl.size();
            vector<int> row;
            graph.push_back(row);
        }
        makeGraph();
    }
    
    int numVertices(){
        return vertices;
    }

    int numEdges(){
        return edges/2;
    }
    
    int largestDegree(vector<int>&);
    //add an edge to a graph
    void addEdge(int, int);

    void makeGraph();

    //get the word in a graph using an id
    string getWord(int);

    //check if word is in the graph.
    int checkWord(string);

    int cWHelper(string,int,int);

    //degree of a vertex
    int checkDegree(int);

    //check if two words are neighbors
    bool checkNeighbor(int, int);
    //neighborhood of a vertex
    void getNeighborhood(int);

    //eccntricity of a vertex
    int getEccentricity(int);
    //shortest path between two words
    vector<int> shortestPath(int, int);

    //breadth first search
    void BFS(int, vector<int>&, vector<int>&, vector<int>&, int&);

    //connected components
    vector<int> connectedComponent(int&);

    protected:

    private:
    const vector<string>& wl;
    vector< vector<int> > graph;

    int vertices = 0;
    int edges = 0;

};

#endif
