#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int N_max = 2000;

bool read(int& n, int& cnt, string words[N_max]){
    ifstream in("input8.txt");
    if(!in.is_open()){
        cerr << "File not found";
        return false;
    }

    in >> n;
    cnt = 0;

    while(!in.eof()){
        in >> words[cnt];
        cnt++;
    }
    return true;
}

void write(int n, int cnt, string words[N_max], int cletters[N_max]){
    ofstream out("output.txt");
    string prev = "";
    for(int i=0;i<cnt;i++){
        if(n==0){
            break;
        }
        
        if(words[i] != prev){
            prev = words[i];
            out << "<" << words[i] << ">" << "-" << cletters[i] << "-\n";
            n--;
        }
        
    }
}

void ClearWords(int cnt, string words[N_max]){
    for(int i=0;i<cnt;i++){
        for(int j=0; j<words[i].length(); j++){
            if(!isalpha(words[i][j])) {
                words[i].erase(j, 1);
                j--;
            }
        }
    }
}
void CEL(int cnt, string words[N_max], int cletters[N_max]){
    for(int i=0; i<cnt; i++){
        char letters[256] = {0};
        for(int j=0; j<words[i].length(); j++){
            char c = tolower(words[i][j]);
            letters[c]++;
        }
        int max = INT_MIN;
        for(int k=0;k<256;k++){
            if (letters[k] > max){
                max = letters[k];
            }
        }
        cletters[i] = max;
    }
}
void sort(int cnt, string words[N_max], int cletters[N_max]){
    for(int i=0;i<cnt-1;i++){
        for(int j=i+1;j<cnt;j++){
            if((cletters[i] < cletters[j]) || (cletters[i] == cletters[j] && words[i] < words[j])){
                int obm = cletters[i];
                cletters[i] = cletters[j];
                cletters[j] = obm;
                string x = words[i];
                words[i] = words[j];
                words[j] = x;
            }
        }
    }
}

int main(){
    int n;
    int cnt;
    string words[N_max];
    int cletters[N_max] = {0};
    if (!read(n, cnt, words)){
        return -1;
    }
    ClearWords(cnt, words);
    CEL(cnt, words, cletters);
    sort(cnt, words, cletters);
    write(n, cnt, words, cletters);
    return 0;
}