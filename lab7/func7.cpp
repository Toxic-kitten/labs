#include "func7.hpp"
#include <iostream>
using namespace std;

void read(int matrix[100][100], int& n, int& m){
    cout << "How many strok do you want to enter?\n";
    cin >> n;
    cout << "How many stolb do you want to enter?\n";
    cin >> m;
    cout << "Your matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }
}

void write(int matrix[100][100], int& n, int& m){
    cout << "Final matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

bool RavnStolb(int matrix[100][100], int& n, int& m){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            if (matrix[i][j] == matrix[i][j+1]){
                return true;
            }
        }
    }
    return false;
}

bool isPrime(int matrix[100][100], int& n, int& m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x = matrix[i][j];
            if (x<2){
                return false;
            }
            double sqrtX = sqrt(x);
            for(int d=2; d<=sqrtX; d++){
                if (abs(x) % d == 0){
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}

int SumStroki(int matrix[100][100], int& n, int& m, int& s){
    int i = s;
    int sum = 0;
    for(int j=0; j<m; j++){
        sum += matrix[i][j];
    }
    return sum;
}

void SortStrokPoVozrast(int matrix[100][100], int& n, int& m){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if (SumStroki(matrix, n, m, i) > SumStroki(matrix, n, m, j)){
                for(int k=0; k<m; k++){
                int tmp = matrix[i][k];
                matrix[i][k] = matrix[j][k];
                matrix[j][k] = tmp;
                }
            }
        }
    }
}
