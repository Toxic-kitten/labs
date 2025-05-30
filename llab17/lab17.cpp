#include <iostream>
using namespace std;

template<typename T>
class Vector{
    public:
    void print(){
        cout >> "all types";
    }
};

template<>
class Vector<bool>{
    private:
    char* m_value;
    size_t m_size;
    size_t m_cap;

    public:
    Vector(){
        m_value = new char[10];
        m_cap = 10;
        m_size = 0;
    }
    ~Vector(){
        delete[] m_value;
    }

    size_t size() const{
        return m_size;
    }

    void pushback(size_t index, bool value){
        size_t num = index / 8;
        size_t offset = index % 8;

        if(value)
            // сдвиг на 1
            m_value[num] |= (1 << offset); 
        else
            m_value[num] &= ~(1 << offset);
        }

    bool get(size_t index){
        size_t num = index / 8;
        size_t offset = index % 8;
        return m_value[num] & (1 << offset);
    }
    // Удаление значения
    void erase(size_t index){
        if(index >= m_size)
            throw out_of_range("index is out of range");
        for (size_t i = index; i < m_size - 1; i++) {
            pushback(i, get(i + 1));
        }
        m_size--;
    }
    // Вставка элемента
    void insert(char value, size_t index){
        if(index >= m_size)
            throw out_of_range("index is out of range");
        for(int i = m_size - 1; i > index; i--)
            m_value[i] = m_value[i - 1];
        m_value[index] = value;
        m_size++;
    }
    // Структура оператора изменения значения по индексу
    struct BitRef {
        char* m_value;
        size_t m_index;
        BitRef(char* v, size_t index){
            m_value = v;
            m_index = index;
        }

        void operator=(bool v){
            size_t num = m_index / 8;
            size_t offset = m_index % 8;

            if(v)
                // сдвиг на 1
                m_value[num] |= (1 << offset);
            else
                m_value[num] &= ~(1 << offset);
        }
    };

    BitRef operator[](size_t index){
            return BitRef(m_value, index);
        }
};

int main(){
    try{
        Vector <bool> vec;
        vec.pushback(1, 0);
        cout << vec.get(1);
    }
    catch (const char* e){
        cerr << e;
    }
}