#include <iostream>
using namespace std;

int main(){   
    // Задание №2
    // Ввод чисел
    const auto size2 = 10000;
    int mas2[size2]{};
    int n;
    cout << "\t\tTask 2\n";
    cout << "How many numbers do you want to enter?\n";
    cin >> n;
    cout << "Enter your numbers: ";
    for(int i=0; i<n; i++) {
        cin >> mas2[i];
    }

    // Сортировка
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {

            int firI = mas2[i];
            while(firI > 9) firI /= 10;

            int firJ = mas2[j];
            while(firJ > 9) firJ /= 10;

            int sumI = 0;
            int one = mas2[i];
            while (one > 0){
                sumI += one % 10;
                one /= 10;
            }
            int sumJ = 0;
            int two = mas2[j];
            while (two > 0){
                sumJ += two % 10;
                two /= 10;
            }

            if (firI > firJ) {
                auto xp = mas2[i];
                mas2[i] = mas2[j];
                mas2[j] = xp;
            }
            else if(firI == firJ && sumI > sumJ){
                auto xp = mas2[i];
                mas2[i] = mas2[j];
                mas2[j] = xp;
            }
            else if((firI == firJ) && (sumI == sumJ) && (mas2[i] > mas2[j])){
                auto xp = mas2[i];
                mas2[i] = mas2[j];
                mas2[j] = xp;
            }
        }
    }


    // Вывод чисел
    cout << "Result: ";
    for(int i=0; i<n; i++) {
        cout << mas2[i] << " ";
    }
}