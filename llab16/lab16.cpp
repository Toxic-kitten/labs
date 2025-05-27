#include <iostream>
using namespace std;

template<typename T, int N, int M>
class Matrix {
    // Т.к размер известен на этапе компиляции, то матрица будет создана на стеке,
    // а если это так, то мы можем обойтись без деструктора, конструктора копирования
    // и оператора присваивания копирования
    T m_mat[N][M];
public:
    // Конструктор
    Matrix(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                m_mat[i][j] = 0;
            }
        }
    }
    // Оператор присваивания копирования(с ним легче)
    Matrix& operator=(const Matrix& other){
        if(this != &other){
            for(int i=0;i<N;i++){
                for(int j=0;j<M;j++){
                    m_mat[i][j] = other.m_mat[i][j];
                }
            }
            return *this;
        }  
        return *this;
    }

    T& operator()(size_t i, size_t j) {
        return m_mat[i][j];
    }
    
    T& operator()(size_t i, size_t j, size_t k) {
        m_mat[i][j] = k;
        return m_mat[i][j];
    }

    // Ввод
    void Add(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                cin >> m_mat[i][j];
    }

    // Вывод
    void Print(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cout << m_mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    Matrix& operator+=(const Matrix& other){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                m_mat[i][j] += other.m_mat[i][j];
            }
        }
        return *this;
    }

    Matrix& operator+(const Matrix& other){
        Matrix value(*this);
        value += other;
        return value;
    }

    // Умножение на число
    Matrix& operator*=(int value){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                m_mat[i][j] *= value;
            }
        }
        return *this;
    }

    Matrix& operator*=(const Matrix& other){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                m_mat[i][j] *= other.m_mat[i][j];
            }
        }
        return *this;
    }

    Matrix& operator*(const Matrix& other){
        Matrix value(*this);
        value *= other;
        return value;
    }

    Matrix operator++(int){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                m_mat[i][j]++;
            }
        }
        return *this;
    }

    Matrix& operator++(){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                m_mat[i][j] = 1 + m_mat[i][j];
            }
        }
        return *this;
    }

    T Det() const{
        if(N == 1)
            return m_mat[0][0];
        if(N == 2)
            return m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];

        if(N == 3)
            return ((m_mat[0][0] * m_mat[1][1] * m_mat[2][2] + m_mat[1][0]*m_mat[2][1]*m_mat[0][2] + m_mat[0][1]*m_mat[1][2]*m_mat[2][0])
                - m_mat[0][2] * m_mat[1][1] * m_mat[2][0] - m_mat[0][0]*m_mat[2][1]*m_mat[1][2] - m_mat[0][1]*m_mat[1][0]*m_mat[2][2]);
    }
};


int main() {
    Matrix<int, 3, 3> A;
    Matrix<int, 3, 3> B;
    Matrix<int, 3, 3> C;
    A.Add();
    cout << "----------" << "\n";
    B.Add();
    C = A * B;
    C.Print();
    return 0;
}