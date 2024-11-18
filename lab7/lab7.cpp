#include <iostream>
#include "func7.hpp"
using namespace std;

int main(){
    int strok;
    int stolb;
    int matrix[100][100];
    read(matrix, strok, stolb);
    if (RavnStolb(matrix, strok, stolb) && isPrime(matrix, strok, stolb) == true){
        SortStrokPoVozrast(matrix, strok, stolb);
    }
    write(matrix, strok, stolb);
}

