#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
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

void search_popular_letters(int n, int count_words[256], string words[N_max]){
    for(int i=0;i<n;i++){
        for(int j=0;j<words[i].length();j++){
            char c = tolower(words[i][j]);
            count_words[c]++;
        }
    }
}

void add_code_words(int n, int code_words[256]){
    int k = 0;
    for(int i=0;i<256;i++){
        code_words[i] = k;
        k+=1;
    }
}

void sort_popular_letters(int n, int count_words[256], int code_words[256]){
    for(int i=0;i<256-1;i++){
        for(int j=i+1;j<256;j++){
            if(count_words[i] < count_words[j]){
                swap(count_words[i], count_words[j]);
                swap(code_words[i], code_words[j]);
            }
        }
    }
}

int main(){
    int n;
    string words[N_max];
    int code_words[256]{};
    int count_words[256]{};
    read(n, words);
    add_code_words(n, code_words);
    search_popular_letters(n, count_words, words);
    sort_popular_letters(n, count_words, code_words);
    for(int i=0;i<256;i++){
        char bykva = code_words[i];
        if (count_words[i] != 0){
            cout << count_words[i] << ' ';
            cout << code_words[i] << ' ';
            cout << bykva << '\n';
        }
    }

    // write(n, words);
}