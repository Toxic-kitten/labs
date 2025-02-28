#include <iostream>
#include <fstream>
using namespace std;
#define mx_k_strok 100
#define mx_k_stolb 100

int k_strok, k_stolb;
char pole[mx_k_strok][mx_k_stolb];
int steps[mx_k_strok][mx_k_stolb];

void Search(int i, int j, int step){
    if(steps[i][j] <= step){
        return;
    }
    steps[i][j] = step;
    if(pole[i][j] == 'E'){
        return;
    }
    if(i+1 < k_strok && pole[i+1][j] != '#'){
        Search(i+1, j, step + 1);
    }
    if(i-1 >= 0 && pole[i-1][j] != '#'){
        Search(i-1, j, step + 1);
    }
    if(j+1 < k_stolb && pole[i][j+1] != '#'){
        Search(i, j+1, step + 1);
    }
    if(j-1 >= 0 && pole[i][j-1] != '#'){
        Search(i, j-1, step + 1);
    }

    if(i + 1 < k_strok && j + 1 < k_stolb && pole[i+1][j+1] != '#'){
        Search(i+1, j+1, step+1);
    }
    if(i - 1 >= 0 && j - 1 >= 0 && pole[i-1][j-1] != '#'){
        Search(i-1, j-1, step+1);
    }
    if(i - 1 >= 0 && j + 1 < k_stolb && pole[i-1][j+1] != '#'){
        Search(i-1, j+1, step+1);
    }
    if(i + 1 < k_strok && j - 1 >= 0 && pole[i+1][j-1] != '#'){
        Search(i+1, j-1, step+1);
    }
}

int main(){
    int Si, Sj, Ei, Ej;
    ifstream in("input.txt");
    in >> k_strok >> k_stolb;
    for(int i=0; i<k_strok; i++){
        for(int j=0; j<k_stolb; j++){
            in >> pole[i][j];
            steps[i][j] = INT_MAX;
            if(pole[i][j] == 'S'){
                Si = i;
                Sj = j;
            }
            else if(pole[i][j] == 'E'){
                Ei = i;
                Ej = j;
            }
        }
    }
    Search(Si, Sj, 0);
    if(steps[Ei][Ej] >= k_stolb * k_strok){
        cout << -1;
    }
    else{
        cout << steps[Ei][Ej];
    }
}