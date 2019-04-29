#ifndef igraph_h
#define igraph_h
#include <cstddef>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <cmath>
#include <cassert>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

class Igraph {

    public:
    Igraph(const vector<string>& w): wl(w) {}
   
    //add an edge to a graph
    void addEdge(int, int);

    //check if word is in the graph.
    bool checkWord(string);

    //degree of a vertex
    int checkDegree(int);
    //neighborhood of a vertex
    void checkNeighborhood(int);

    //eccntricity of a vertex

    //shortest path between two words

    protected:

    private:
    const vector<string>& wl;
    vector<vector<int> > graph;




};

#endif

/*
Questions:
1. how to store the wl without it hating us
2. how to do the numbers of the words
3. the check if in graph method is supposed to be logn. do you need to keep words ordered somehow?
4. components clarification
*/