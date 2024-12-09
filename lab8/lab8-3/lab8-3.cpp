#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <array>
using namespace std;

const int N_max = 5120;

bool read(int& n, string words[N_max]){
    ifstream in("input8-3.txt");
    if(!in.is_open()){
        cout << "file not found!";
        return false;
    }
    
    n = 0;
    while(!in.eof()){
        in >> words[n];
        n++;
    }

    return true;
}

void write(int& n, string words[N_max]){
    for(int i=0;i<n;i++){
        cout << "<" << words[i] << ">\n";
    }
}

int main(){
    int n;
    string words[N_max];
    read(n, words);
    write(n, words);
}