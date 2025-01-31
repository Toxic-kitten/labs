#include <iostream>
using namespace std;

unsigned long long factorial(int num){
    if(num > 1) {
        return num * factorial(num -1);
    }
    return 1;
}

int main(){
    int n = 19;
    for(int i=1;i<=n;i++){
        cout << "The factorial of the number " << i << " is: " << factorial(i) << "\n";
    }
}