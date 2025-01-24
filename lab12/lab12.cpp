#include <iostream>
using namespace std;

int factorial(int num, int fac){
    while(num > 0){
        fac = fac * num * factorial(num-1, fac);
    }
    return fac;
}

int main(){
    int n = 19;
    unsigned long fac = 1;
    cout << factorial(3, fac);
    // for(int i=1;i<=n;i++){
    //     cout << "The factorial of the number " << i << " is: " << factorial(i) << "\n";
    // }
}