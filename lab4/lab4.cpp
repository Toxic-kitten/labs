#include <iostream>

using namespace std;

int main(){
    cout << "\t\tTask 1\n";
    int a;
    int b;
    int c;
    cout << "Enter the number A: ";
    cin >> a;
    cout << "Enter the number B: ";
    cin >> b;
    cout << "Enter the number C: ";
    cin >> c;
    if (a % b == 0 && b > c){
        cout << "Answer: " << a / b + c << "\n";
    }
    else if (a % b == 0 && b < c){
        cout << "Answer: " << a / b - c << "\n";
    }
    else {
        cout << "Answer: " << (a+b)*c << "\n";
    }

    cout << "\t\tTask 2\n";
    int n;
    cout << "Enter the month number: ";
    cin >> n;
    switch(n) {
        case 1:
        case '01':
            cout << "It's January";
            break;
        case 2:
        case '02':
            cout << "It's February";
            break;
        case 3:
        case '03':
            cout << "It's March";
            break;
        case 4:
        case '04':
            cout << "It's April";
            break;
        case 5:
        case '05':
            cout << "It's May";
            break;
        case 6:
        case '06':
            cout << "It's June";
            break;
        case 7:
        case '07':
            cout << "It's July";
            break;
        case 8:
        case '08':
            cout << "It's August";
            break;
        case 9:
        case '09':
            cout << "It's September";
            break;
        case 10:
            cout << "It's October";
            break;
        case 11:
            cout << "It's November";
            break;
        case 12:
            cout << "It's December";
            break;
        default:
            cout << "This month does not exist!";
    }
   cout << "\n\t\tTask 3\n";
   int x;
   cout << "Select the value of x\n";
   cout << "X can be equal to 1 or -1!\n";
   cout << "Your option: ";
   cin >> x;
   switch(x){
    case 1:
        cout << "It's Positive number";
        break;
    case -1:
        cout << "It's Negative number";
        break;
    default:
        cout << "Enter 1 or -1!";
   }
}