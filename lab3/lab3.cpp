#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

std::string bitsetView(std::bitset<36> b)
{
    std::string res = b.to_string();
    res.erase(0, res.find('1'));
    return res;
}

int main(){
    long long x;
    cout << "Yout digit: ";
    cin >> x;
    int one = 0b0000'0001;
    int n;
    cout << "Which digit do you want to replace with 1?\n";
    cout << "Shift to: ";
    cin >> n;
    int shift = one << n;
    long long ans = shift | x;
    cout << "Answer: ";
    std::cout << bitsetView(std::bitset<36>(ans)) << std::endl;
}