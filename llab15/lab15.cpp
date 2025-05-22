#include <iostream>
using namespace std;

class MyVector {
    int* m_arr;
    size_t m_size;
    size_t m_cap;
public:
    // Конструктор для пустого вектора
    MyVector() {
        m_size = 0;
        m_cap = 0;
        m_arr = nullptr;
    }
    // Конструктор для обычного вектора
    MyVector(size_t size) {
        m_size = size;
        m_cap = m_size;
        m_arr = new int[m_size];
        for(int i=0; i<m_size;i++)
            m_arr[i] = 0;
    }
    // Конструктор копирования
    MyVector(const MyVector& other) {
        m_size = other.m_size;
        m_cap = other.m_cap;
        m_arr = new int[m_size];
        for(int i=0;i<m_size;i++){
            m_arr[i] = other.m_arr[i];
        }
    }

    // Оператор присваивания копирования
    MyVector& operator=(const MyVector& other){
        if(&other != this){
            int* tmp = new int[other.m_size];
            for(int i=0;i<other.m_size;i++){
                tmp[i] = other.m_arr[i];
            }

            if(m_arr != nullptr){
                delete[] m_arr;
            }
            m_arr = tmp;
            m_size = other.m_size;
            m_cap = other.m_cap;
            return *this;
        }
    }

    ~MyVector() {
        if(m_arr != nullptr){
            delete[] m_arr;
        }
    }

    //

    size_t size() {
        return m_size;
    }

    size_t capacity() {
        return m_cap;
    }

    void reserve(size_t cap) {
        if(m_cap >= cap){
            return;
        }
        m_cap = cap;
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++) {
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    }

    void shrink_to_fit() {
        m_cap = m_size;
        int* tmp = new int[m_cap];
        for(int i=0;i<m_size;i++) {
            tmp[i] = m_arr[i];
        }
        delete m_arr;
        m_arr = tmp;
    }

    int& back() {
        return m_arr[m_size-1];
    }

    int& front() {
        return m_arr[0];
    }

    int& operator[](size_t index) {
        return m_arr[index];
    }

    bool empty(){
        if(m_arr == nullptr){
            return true;
        }
        return false;
    }

    void push_back(int value) {
        if(m_size + 1 <= m_cap){
            m_arr[m_size] = value;
            m_size++;
        }
        else {
            m_size++;
            m_cap = m_cap * 2 + 1;
            int* tmp = new int[m_cap];
            for(int i=0;i<m_size-1;i++){
                tmp[i] = m_arr[i];
            }
            tmp[m_size-1] = value;
            delete[] m_arr;
            m_arr = tmp;
        }
    }

    void insert(size_t pos, size_t value){
        if(m_size + 1 > m_cap){
            m_cap = m_size;
        }
        m_size += 1;
        m_cap += 1;
        int* tmp = new int[m_size];
        for(int i=0;i<pos;i++){
            tmp[i] = m_arr[i];
        }
        tmp[pos] = value;
        for(int i=pos;i<m_size;i++){
            tmp[i+1] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    }

    void erase(size_t pos){
        if(pos < m_size){
            for(int i=m_size-1;i>=pos;i--){
                m_arr[i] = m_arr[i+1];
            }
            m_size -= 1;
        }
    }

    void erase(size_t start, size_t end){
        if(start <= m_size && end <= m_size){
            int* tmp = new int[m_size];
            int razn = (end - start) + 1;
            for(int i=0;i<start;i++){
                tmp[i] = m_arr[i];
            }
            for(int i=end;i<m_size;i++){
                tmp[start] = m_arr[i+1];
                start += 1;
            }
            delete[] m_arr;
            m_arr = tmp;
            m_size -= razn;
        }
    }

    void resize(size_t n){
        if(m_size >= n){
            int* tmp = new int[m_size];
            for(int i=0;i<n;i++){
                tmp[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = tmp;
            m_size = n;
            m_cap = n;
        }
    }

    void resize(size_t n, size_t value){
        if(m_size >= n){
            int* tmp = new int[m_size];
            for(int i=0;i<n;i++){
                tmp[i] = m_arr[i];
            }
            delete[] m_arr;
            m_arr = tmp;
            m_size = n;
            m_cap = n;
        }
        else {
            int* tmp = new int[n];
            for(int i=0;i<m_size;i++){
                tmp[i] = m_arr[i];
            }
            for(int i=m_size;i<n;i++){
                tmp[i] = value;
            }
            delete[] m_arr;
            m_arr = tmp;
            m_size = n;
            m_cap = n;
        }
    }

    // Сделанно
    // А. resize(n, value): оставляет в векторе n первых 
    // элементов. Если размер вектора меньше n, то добавляются 
    // недостающие элементы со значением value
    // G. empty Функция проверяет, есть ли элементы в векторе
    // J. insert(pos, value): вставляет элемент value на позицию, 
    // на которую указывает итератор pos
    // K. erase(p): удаляет элемент, на который указывает итератор p
};

int main() {
    // MyVector a(10);
    // MyVector b(15);
    // MyVector c;
    // if (c.empty()){
    //     cout << "empty";
    // }
    // else {
    //     cout << "no empty";
    // }
    MyVector vec;
    MyVector n;
    for(int i=0;i<3;i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    vec.insert(0, 0);
    n = vec;
    n.resize(6, 7);
    for(int i=0;i<n.size();i++){
        cout << n[i] << " ";
    }
    // vec.shrink_to_fit();
    // cout << vec.size() << " " << vec.capacity() << "\n";
    // cout << vec.back() << "\n";
    // cout << vec.front() << "\n";
    // cout << vec[1];
}