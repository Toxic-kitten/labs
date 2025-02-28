#include <iostream>
#include <thread>
using namespace std;

int median_element(int* arr){
    int first = arr[0];
    int last = arr[n-1];
    int med = arr[n/2];
    int const d = 3;
    int mas[d] = {first, last, med};
    for(int i=0; i<d; i++){
        for(int j=i+1; j<d; j++){
            if(mas[i] > mas[j]){
                int tmp = mas[j];
                mas[j] = mas[i];
                mas[i] = tmp;
            }
        }
    }
    return mas[1];
}

void Quick_sort(int a, int b, int* arr){
    if(a>=b) {
        return;
    }
    int med = median_element(arr);
    int left = a - 1;
    int right = b + 1;
    while(1) {
        do left++; while(arr[left] < med);
        do right--; while(arr[right] > med);
        if(left >= right){
            break;
        }
        swap(arr[left], arr[right]);
    }
    left = right;
    right++;
    Quick_sort(a, left, arr);
    Quick_sort(right, b, arr);
}

int main(){
    const int n = 6;
    int arr[n] = {2, 4, 1, 3, 6, 5};
    Quick_sort(0, n-1, arr);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}