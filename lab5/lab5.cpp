#include <iostream>
using namespace std;

int main(){
    cout << "\t\tTask 1\n";
    const int k = 6;
    int numbers[k];

    int i;
    cout << "Enter numbers(max " << k << " numbers): ";
    for(i = 0; i < k; i++){
        cin >> numbers[i];
    }

    int result;
    cout << "The product of numbers: ";
    for(i=0, result=1; i < k; i++){
        if (numbers[i] % 10 == 2 || numbers[i] % 10 == 4){
            result *= numbers[i];
        }
    }
    cout << result;

    cout << "\nMinimum number: ";
    auto minnum = 1000000;
    int placemin;
    for(i = 0; i < k; i++){
        if (numbers[i] % 10 == 2 || numbers[i] % 10 == 4){
            if (minnum > numbers[i]){
                minnum = numbers[i];
                placemin = i;
            }
        }
    }
    cout << minnum;
    cout << "\nPlace in the sequence: ";
    cout << placemin;

}
