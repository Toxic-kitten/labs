#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int N_max = 5120;
bool read(int& n, string words[N_max]){
    ifstream in("input8-2.txt");
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

void ClearWords(int n, string words[N_max]){
    for(int i=0;i<n;i++){
        for(int j=0; j<words[i].length(); j++){
            if(!isalpha(words[i][j])) {
                words[i].erase(j, 1);
                j--;
            }
        }
    }
}

bool Are_palindromes(int n, string words[N_max]){
    for(int i=0;i<n;i++){
        string a{""};
        for(int j=words[i].length()-1; j>-1; j--){
            char w = words[i][j];
            a += w;
        }
        if(words[i].length() > 1 && words[i] == a){
            return true;
            break;
        }
    }
    return false;
}

void CountOfConsonants(int n, string words[N_max], string consonants[N_max]){
    string sogl = {"BCDFGHJKLMNPQRSTVWXZ"};
    for(int i=0;i<n;i++){
        char cons = {0};
        for(int j=0;j<words[i].length();j++){
            for(int k=0;k>sogl.length();k++){
                if(words[i][j] = tolower(sogl[k])){

                }
            }
        }
    }
}

int main(){
    int n;
    string words[N_max];
    string consonanst[N_max] = {0};
    read(n, words);
    ClearWords(n, words);
    if(!Are_palindromes(n, words)){

    }
    write(n, words);
}