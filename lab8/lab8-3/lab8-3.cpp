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
    ofstream out("output.txt");
    for(int i=0;i<n;i++){
        out << "<" << words[i] << "> ";
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

void top_five_letters(int count_words[256], int code_words[256], int five_words_count[5], int five_words[5]){
    for(int i=0;i<5;i++){
        int bykva = code_words[i];
        five_words_count[i] = count_words[i];
        five_words[i] = bykva;
    }
}

void toUpper(int n, int index, string words[N_max]){
    int i = index;
    for(int j=0;j<words[i].length();j++){
        words[i][j] = toupper(words[i][j]);
    }
}

void found_letters(int n, string words[N_max], int five_words[5]){
    for(int i=0;i<n;i++){
        int cnt = 0;
        string pop_lett_in_word;
        for(int j=0;j<words[i].length();j++){
            for(int k=0;k<5;k++){
                char bykva = tolower(words[i][j]);
                char pop_bykva = five_words[k];
                if(bykva == pop_bykva){
                    cnt += 1;
                    pop_lett_in_word += pop_bykva;
                }
            }
            if (cnt >= 4){
                toUpper(n, i, words);
                words[i] += "(";
                for(int r=0;r<5;r++){
                    char c = pop_lett_in_word[r];
                    words[i] += c;
                }
                words[i] += ")";
                break;
            }
        }
    }
}


int main(){
    int n;
    string words[N_max];
    int code_words[256]{};
    int count_words[256]{};
    int five_words[5]{};
    int five_words_count[5]{};
    read(n, words);
    add_code_words(n, code_words);
    search_popular_letters(n, count_words, words);
    sort_popular_letters(n, count_words, code_words);
    top_five_letters(count_words, code_words, five_words_count, five_words);
    found_letters(n, words, five_words);
    write(n, words);
}