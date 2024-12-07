#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <array>
using namespace std;

const int N_max = 5120;

bool read(string words[N_max]){
    ifstream infile("input8-3.txt");
    if(!infile.is_open()){
        cerr << "File not found";
        return false;
    }

    string text;
    while (infile.good()) {
        string line;
        getline(infile, line);
        text += line + "\n";
    }
    infile.close();
}

void write(string words[N_max]){
    ofstream outfile("output.txt");
    for(int i=0;i<N_max; i++){
        outfile << words[i];
    }
}

int main(){
    string words[N_max];
    read(words);
    write(words);
}