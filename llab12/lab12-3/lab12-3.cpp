#include <iostream>
#include <fstream>
using namespace std;
#define mx_k_strok 100
#define mx_k_stolb 100

int k_strok, k_stolb;
char pole[mx_k_strok][mx_k_stolb];
int steps[mx_k_strok][mx_k_stolb];

void Search(int i, int j, int k_strok, int k_stolb, char pole[mx_k_strok][mx_k_stolb], int steps[mx_k_strok][mx_k_stolb], int step){

}

int main(){
    ifstream in("input.txt");
    in >> k_strok >> k_stolb;
    for(int i=0; i<k_strok; i++){
        for(int j=0; i<k_stolb; j++){
            in >> pole[i][j];
        }
    }
}