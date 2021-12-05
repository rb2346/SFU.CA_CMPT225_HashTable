#include <iostream>
#include "HashTable.h"
#include "spellcheck.h"
#include <string>
#include <fstream>

using namespace std;

int main() {
    HashTable h;

    fstream infile;
    infile.open("wordlist1000.txt", ios::in);

    string fileword;
    if(infile.is_open())
        while(getline(infile, fileword)){
            cout << fileword;
            cout << "inserting" << endl;
            h.insert(fileword);
        }
    else
        cout << "file not opwn" << endl;


    vector<string> res = extraLetter(h, "chate");
    cout << "extraLetter(chate) : ";
    for(auto& i : res){
        cout << i << " | ";
    }
    cout << endl;

    res = transposition(h, "atr");
    cout << "transposition(atr) : ";
    for(auto& i : res){
        cout << i << " | ";
    }
    cout << endl;


    res = missingSpace(h, "rateat");
    cout << "missingSpace(rateat) : ";
    for(auto& i : res){
        cout << i << " | ";
    }
    cout << endl;


    res = missingLetter(h, "poe");
    cout << "missingLetter(poe) : ";
    for(auto& i : res){
        cout << i << " | ";
    }
    cout << endl;


    res = incorrectLetter(h, "thed");
    cout << "incorrectLetter(thed) : ";
    for(auto& i : res){
        cout << i << " | ";
    }
    cout << endl;

    cout << "done";
}
