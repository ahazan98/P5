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
    vector<int> comp = graph.connectedComponent();
    cout << setw(5);
    cout << "Number of vertices: " <<  endl;
    cout << "Number of edges:" << endl;
    cout << "Number of components:" << comp.size() << endl;
    cout << "Largest component:" << endl;
    cout << "Largest Degree:" << endl;
    cout << endl;

    char next;
    do{
        cout << "Command (d/i/q)? ";
        cin >> next;
        if(next =='d'){
            continue;
        }
        if(next == 'i'){
            continue;
        }
        if(next != 'q'){
            cout <<"Please enter either d, i or q!" << endl;
        }
    }while(next != 'q');
    cout << "Thanks for plyaing!" << endl;
    return 0;

}
