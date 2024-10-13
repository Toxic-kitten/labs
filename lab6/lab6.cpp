#include <iostream>
using namespace std;

int main(){
    // Ввод чисел в массив
    const auto size = 10000;
    int mas[size]{};
    int k;
    cout << "How many numbers do you want to enter?\n";
    cin >> k;
    cout << "Enter your numbers: ";
    for(int i=0; i<k; i++) {
        cin >> mas[i];
    }

    // Проверка условия
    int flag = 0;
    for(int i=0; i<k; i++) {
        if (mas[i] == 1 | mas[i]/10==1 | mas[i]/100==1 | mas[i]/1000==1 | mas[i] == 10000){
            flag = 1;
        }
    }

    // Сортировка чисел
    if (flag == 1){
        for(int i=0; i<k-1; i++) {
            for(int j=i+1; j<k; j++) {
                if (mas[i] > mas[j]) {
                    auto xp = mas[i];
                    mas[i] = mas[j];
                    mas[j] = xp;
                }
            }
        }
    }

    // Вывод чисел
    cout << "Result: ";
    for(int i=0; i<k; i++) {
        cout << mas[i] << " ";
    }
}