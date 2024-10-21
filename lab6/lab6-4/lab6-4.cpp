#include <iostream>
using namespace std;

int main(){   
    // Задание №4
    cout << "\n\t\tTask 4\n";
    const int kolvo = 20000;
    int yourk;
    cout << "How many numbers do you want to enter?\n";
    cin >> yourk;
    int mac[kolvo];

    // Ввод чисел в массив 
    cout << "Enter your numbers: ";
    for (int i = 0; i < yourk; i++){
        cin >> mac[i];
    }

    // Удаление лишних чисел
    for (int i = 0; i < yourk; i++){
        bool flagg = 0;
        int x = mac[i];
        int y = 0;
        while (x>0){
            y = x % 10;
            if (y == 7){
                flagg = 1;
            }
            else if (y == 6){
                flagg = 0;
                break;
            }
            else {
                flagg = 0;
            }
            x /= 10;
        }
        if (flagg==1){
            for (int j = i; j < yourk-1; j++){
                mac[j] = mac[j+1];
            }
            i--;
            yourk--;
        }
    }

    // Поиск простых чисел
    // Дублирование простых чисел
    for (int i = 0; i < yourk; i++){
        bool simple = 1;
        if (mac[i]==0 || mac[i]==1){
            simple = 0;
        }
        for (int p = 2; p <= mac[i]/2; p++){
            if (mac[i] % p == 0){
                simple = 0;
            }
        }

        if (simple==1){
            for (int j = yourk; j>i; j--){
                mac[j] = mac[j-1];
            }
            i++;
            yourk++;
        }
    }

    // Вывод чисел
    cout << "Result: ";
    for(int i=0; i<yourk; i++) {
        cout << mac[i] << " ";
    }
}