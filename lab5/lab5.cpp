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
    auto minnum = INT_MAX;
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
    cout << "\nPlace in the sequence: " << placemin << "\n";

    cout << "\t\tTask 2\n";
    unsigned long digit;
    int maxx = 0;
    cout << "Enter a number: ";
    cin >> digit;
    while (digit>0)
    {
        int d;
        d = digit % 10;
        if(d > maxx) {
            maxx = d;
        }
        digit /= 10;
    }
    cout << "The maximum digit: " << maxx;
}
