#include <iostream>

using namespace std;

int main(){
    // создаем переменную n типа int
    int n = 1000;
    // создаем указатель p на адрес переменной n
    int *p = &n;
    // приводим указатель к типу unsigned char равному 1 байту, для получения каждого байта переменной n
    // разименновываем указатель чтобы получить первый и последующие байты числа n
    // char *pchar {(char *)(p)};
    int x = ((unsigned char *)(p))[0];
    int y = ((unsigned char *)(p))[1];
    int z = ((unsigned char *)(p))[2];
    int t = ((unsigned char *)(p))[3];
    
    cout << "First byte: " << x << "\n";
    cout << "Second byte: " << y << "\n";
    cout << "Third byte: " << z << "\n";
    cout << "Fourth byte: " << t << "\n";
} 