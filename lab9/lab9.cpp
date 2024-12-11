#include <iostream>

using namespace std;

int main(){
    // создаем переменную n типа int
    int n = 1000;
    // создаем указатель p на адрес переменной n
    int* p = &n;
    // приводим указатель к типу unsigned char равному 1 байту, для получения каждого байта переменной n
    unsigned char* p_char = (unsigned char *)(p);
    // разименновываем указатель и приводим к типу int чтобы получить первый и последующие байты числа n
    // выводим каждый байт числа с помощью прибавления единицы к указателю до разименнации
    for(int i=0;i<4;i++){
        cout << "Byte " << i << ": " << (unsigned int)(*(p_char+i)) << "\n";
    }

    // Вариант 2
    // int x = ((unsigned char *)(p))[0]; // *(((unsigned char *)(p)) + 1)
    // int y = ((unsigned char *)(p))[1];
    // int z = ((unsigned char *)(p))[2];
    // int t = ((unsigned char *)(p))[3];
    
    // cout << "First byte: " << x << "\n";
    // cout << "Second byte: " << y << "\n";
    // cout << "Third byte: " << z << "\n";
    // cout << "Fourth byte: " << t << "\n";
} 