#include <iostream>

using namespace std;

int main(){
    // создаем переменную n типа int
    int n = 1000;
    // создаем указатель p на адрес переменной n
    int *p = &n;
    // приводим указатель к типу char равному 1 байту, для получения каждого байта переменной n
    char *pchar {(char *)(p)};
    int x = ((unsigned char *)(p))[0];
    // разименновываем указатель чтобы получить первый и последующие байты числа n
    cout << x << "\n";
    // cout << "First byte: " << *pchar << "\n";
}