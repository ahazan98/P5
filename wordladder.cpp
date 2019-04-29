#include "igraph.h"

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
}
