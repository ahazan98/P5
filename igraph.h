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
#include <map>

using namespace std;

class Igraph {

    protected:

    private:
    vector<string> wl;
    map< string,vector<string> > graph;

    public:
    // Igraph();
    Igraph(vector<string> w){
        wl = w;
        vector<string>::iterator ptr;
        for(ptr = w.begin(); ptr < w.end(); ptr++){
            vector<string> temp;
            graph.insert({ptr,temp});
        }
    }


};

#endif
