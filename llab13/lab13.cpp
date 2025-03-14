#include <iostream>
#include <cmath>
using namespace std;

class Square {
    public:
        Square(){
            cout << "Ctor" << "\n";
        }

        int sq_side;
        int sq_area;
        int sq_perim;
        float sq_diagonal;

        int Square_area() {
            sq_area = sq_side * sq_side;
            return sq_area;
        }
        int Square_perimeter(){
            sq_perim = sq_side * 4;
            return sq_perim;
        }
        float Square_diagonal(){
            sq_diagonal = sq_side * sqrt(2);
            return sq_diagonal;
        } 
};

int main(){
    Square square;
    cout << "Enter the side of the square: ";
    cin >> square.sq_side;
    cout << "The area of the square is: ";
    cout << square.Square_area() << "\n";
    cout << "The perimeter of the square is: ";
    cout << square.Square_perimeter() << "\n";
    cout << "The diagonal of the square is: ";
    cout << square.Square_diagonal() << "\n";
}