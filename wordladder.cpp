#include "igraph.h"

using namespace std;

int main(){
    string filename;
    cout << "Enter file name with the words: ";
    cin >> filename;

    ifstream in;
    in.open(filename);
    if(in.fail()){
        cout << "Error openeing file. \n";
        exit(1);
    }

    vector<string> wordlist;
    string word;
    while(in >> word){
        wordlist.push_back(word);
    }

    Igraph graph = Igraph(wordlist);
    // graph.getNeighborhood(graph.checkWord("graph"));
    // vector<int> comp = graph.connectedComponent();
    // cout << comp.size() << endl;
    // graph.getNeighborhood(1);
    // cout << graph.checkWord("aaalii") << endl;

    // vector<int> visited(wordlist.size(),0);
    // vector<int> d(wordlist.size(),0);
    // vector<int> pred(wordlist.size(),0);
    // int numVisited = 0;
    // graph.BFS(1,visited, d, pred,numVisited);

    int maxComp = 0;
    vector<int> comp = graph.connectedComponent(maxComp);
    

    cout << setw(5);
    cout << "   Number of vertices: " << graph.numVertices() << endl;
    cout << "   Number of edges: " << graph.numEdges() <<endl;
    cout << "   Number of components: " << comp.size() << endl;
    cout << "   Largest component: " << maxComp << endl;
    vector<int> words;
    cout << "   Largest Degree: " << graph.largestDegree(words) << " at ";
    if(words.size() ==1){
        cout << graph.getWord(words[0]) << endl;
    }
    else{
        for(int i = 0; i < (words.size()-1); i++){
            cout << graph.getWord(words[i]) << ", ";
        }
        cout << "and " << words[words.size() - 1] << endl;;
    }
    cout << endl;

    char next = 'a';
    
    while(next != 'q'){
        cout << "Command (d/i/q)? ";
        cin >> next;
        if(next =='d'){
            string source;
            string dest;
            cout << "Enter source word (" << graph.getWord(0).size()<< " letters): ";
            cin >> source;
            
            // transform(source.begin(), source.end(), source.begin(), ::tolower);
            
            cout << "Enter destination word: ";
            cin >> dest;
            // transform(dest.begin(), dest.end(), dest.begin(), ::tolower);
            for(int c = 0; c < source.size(); c ++){
                source[c] = tolower(source[c]);
                dest[c] = tolower(dest[c]);

            }

            int sourceId = graph.checkWord(source);
            int destId = graph.checkWord(dest);
            if(sourceId == -1){
                cout << source << " is not in the graph" << endl;
                continue;
            }
            if(destId == -1){
                cout << dest << " is not in the graph" << endl;
                continue;
            }

            vector<int> sp = graph.shortestPath(sourceId,destId);
            if(sp[0] != -1){
                cout << "The path from " << source << " to " << dest << " has " << sp.size() - 1 << " steps " << endl;
                for(vector<int>::reverse_iterator iter = sp.rbegin();iter != sp.rend(); iter++){
                    cout << graph.getWord(*iter) << endl;
                }
            }


            continue;
        }
        else if(next == 'i'){
            
            cout << "Enter source word (" << graph.getWord(0).size()<< " letters): ";
            string source;
            cin >> source;
            int id = graph.checkWord(source);
            for(int c = 0; c < source.size(); c ++){
                source[c] = tolower(source[c]);

            }
            // transform(source.begin(), source.end(), source.begin(), ::tolower);
            if(id == -1){
                cout << source << " is not in the graph" << endl;
                continue;
            }
            cout << "   Degree of graph is: " << graph.checkDegree(id) << endl;
            cout << "   Neighborhood of graph: " << endl;
            graph.getNeighborhood(id);
            cout << "   Eccentricity of graph: " << graph.getEccentricity(id) << endl;
            continue;
        }
        else if (next != 'q'){
            cout <<"Please enter either d, i or q!" << endl;
        }
    }
    cout << "Thanks for playing!" << endl;
    return 0;

}
