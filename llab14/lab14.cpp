#include <iostream>
#include <string>
using namespace std;

class BigInt {
        char m_value[1000]; // m_digits = m_value
        unsigned short m_size = 0;
    public:
        // правило трех
        BigInt(){
            for(int i = 0;i<1000;i++)
	            m_value[i] = 0;
        }

        BigInt(const string& value){ // number = value
            size_t len = value.length(); // m_size = len
            for(int i=0;i<len;i++)
                m_value[i] = value[len-i-1] - '0';
            for(int i=len;i<1000;i++){
                m_value[i] = 0;
            }
            m_size = len;
        }

        // ........ += ...........
        BigInt& operator+=(const BigInt& other) {
            for(int i=0;i<m_size;i++){
                m_value[i] += other.m_value[i];
                if(m_value[i] > 9){
                    m_value[i] -= 10;
                    m_value[i+1]++;
                    if(i+1 == m_size){
                        m_size++;
                    }
                }
            }
            return *this;
        }
        // for digits
        BigInt& operator+=(int other) {
            *this += BigInt(to_string(other));
            return *this;
        }

         // ........ + ...........
        BigInt operator+(const BigInt& other) {
            BigInt result(*this);
            result += other;
            return result;
        }

        
        BigInt& operator*=(const BigInt& other){
            BigInt result("0");
            for (BigInt i("0"); i < (*this); i += BigInt("1"))
            {
                result += other;
            }
            *this = result;
            return *this;
        }

        BigInt operator*(const BigInt& other){
	        BigInt result(*this);
	        result *= other;
	        return result;
        }

        bool operator<(const BigInt& other){
            if(m_size < other.m_size){
                return true;
            }
            else if(m_size > other.m_size){
                return false;
            }
            else {
                for(int i=m_size-1;i>=0;i--){
                    if(m_value[i] < other.m_value[i])
                        return true;
                }
            }
            return false;
        }

        bool operator>(const BigInt& other){
            if(m_size > other.m_size){
                return true;
            }
            else if(m_size < other.m_size){
                return false;
            }
            else {
                for(int i=m_size-1;i>=0;i--){
                    if(m_value[i] > other.m_value[i])
                        return true;
                }
            }
            return false;
        }

        bool operator==(const BigInt& other){
            if (m_size != other.m_size){
                return false;
            }
            for(int i=m_size-1;i>=0;i--){
                if(m_value[i] != other.m_value[i]){
                    return false;
                }
            }
            return true;
        }

        bool operator!=(const BigInt& other){
            return !(*this == other);
        }

        bool operator>=(const BigInt& other){
            return !(*this < other);
        }

        bool operator<=(const BigInt& other){
            return !(*this > other);
        }

        BigInt operator++(int) {
            BigInt result(*this);
            *this += BigInt("1");
            return result;
        }

        BigInt& operator++() {
            *this += BigInt("1");
            return *this;
        }

        friend ostream& operator<<(ostream& out, const BigInt& other);
};

// Оператор ввода
istream& operator>>(istream& in, BigInt& other){
    string s;
    in >> s;
    other = BigInt(s);
    return in;
}

ostream& operator<<(ostream& out, const BigInt& other){
    for(int i=0;i<other.m_size;i++){
                out << static_cast<short>(other.m_value[other.m_size - i - 1]);
            }
            out << "\n";
    return out;
}



int main(){
    BigInt a;
    cin >> a;
    BigInt b;
    cin >> b;

    BigInt c("5");
    c *= a;

    // if(a != b) {
    //     cout << "yes a ne ravno" << "\n";
    // }
    // else {
    //     cout << "no" << "\n";
    // }

    cout << c;
}