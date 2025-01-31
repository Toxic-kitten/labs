#include <iostream>
#include <thread>
using namespace std;

void Quick_sort(int a, int b, int* arr){
    if(a>=b) {
        return;
    }
    int med = arr[(a+b)/2];
    int left = a - 1;
    int right = b + 1;
    while(1) {
        do left++; while(arr[left] >= med);
        do right--; while(arr[right] <= med);
        if(left >= right){
            break;
        }
        swap(arr[left], arr[right]);
    }
    right = left;
    left--;
    Quick_sort(a, left, arr);
    Quick_sort(right, b, arr);
}

int main(){
    int const n = 6;
    int arr[n] = {2, 4, 1, 3, 6, 5};
    Quick_sort(0, n-1, arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}