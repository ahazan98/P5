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

    protected:

    private:
    const vector<string> wl;

    public:
    Igraph();
    Igraph(const vector<string> w){
        wl = w;
    }


};

#endif
