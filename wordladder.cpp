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

    
    vector<int> comp = graph.connectedComponent();
    int sum = 0;
    for(int i = 0; i < comp.size(); i++){
        sum += comp[i];
    }
    cout << sum << endl;

    cout << setw(5);
    cout << "Number of vertices: " << graph.numVertices() << endl;
    cout << "Number of edges: " << graph.numEdges() <<endl;
    cout << "Number of components: " << comp.size() << endl;
    cout << "Largest component: " << endl;
    vector<int> words;
    cout << "Largest Degree:" << graph.largestDegree(words) << " at ";
    // cout << words.size() << endl;
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

    // char next;
    // do{
    //     cout << "Command (d/i/q)? ";
    //     cin >> next;
    //     if(next =='d'){
    //         continue;
    //     }
    //     if(next == 'i'){
    //         continue;
    //     }
    //     if(next != 'q'){
    //         cout <<"Please enter either d, i or q!" << endl;
    //     }
    // }while(next != 'q');
    // cout << "Thanks for playing!" << endl;
    // return 0;

}
