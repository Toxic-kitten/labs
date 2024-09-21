#include <iostream>
#include <math.h>
using namespace std;


int main(){
    int a;
    int b;
    int c;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    cout << "Input c: ";
    cin >> c;
    int p = (a+b+c) / 2.0;
    float s = sqrt(p*(p-a)*(p-b)*(p-c));
    cout << "S = " << s;
}