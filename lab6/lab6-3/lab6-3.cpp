#include <iostream>
using namespace std;

int main(){
    // Задание №3
    cout << "\n\t\tTask 3\n";
    int matrix[100][100];

    int n, m;
    cout << "How many strok do you want to enter?\n";
    cin >> n;
    cout << "How many stolb do you want to enter?\n";
    cin >> m;

    // Ввод чисел в матрицу
    cout << "Your matrix:\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }

    // Проверка условия
    int minsum = INT_MAX;
    int minstrok = 0;
    for(int i=0; i<n; i++){
        int sumstrok = 0;
        for(int j=0; j<m; j++){
            sumstrok += matrix[i][j];
        }
        if (sumstrok < minsum){
            minsum = sumstrok;
            minstrok = i;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == minstrok){
                matrix[i][j] = 0;
            }
        }
    }

    // Вывод чисел
    cout << "----Result----\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}