#include <iostream>
// using namespace std

int main()
{
    std::cout << "\t\tTask 1" << std::endl;
    std::cout << "LOGICAL TYPE:" << std::endl;
    std::cout << "bool:\t" << sizeof(bool) << " bite\t" << "true or false" << std::endl;

    std::cout << "INTEGER TYPES:" << std::endl;
    std::cout << "signed char:\t" << sizeof(signed char) << " bite\t" << "[-128;127]" << std::endl;
    std::cout << "unsigned char:\t" << sizeof(unsigned char) << " bite\t" << "[0;255]" << std::endl;
    std::cout << "char:\t" << sizeof(char) << " bite\t" << "[-128;127] or [0;255]" << std::endl;
    std::cout << "short:\t" << sizeof(short) << " bite\t" << "[-32768;32767]" << std::endl;
    std::cout << "unsigned short:\t" << sizeof(unsigned short) << " bite\t" << "[0;65535]" << std::endl;
    std::cout << "int:\t" << sizeof(int) << " bite\t" << "[-2 147 483 648;2 147 483 647]" << std::endl;
    std::cout << "unsigned int:\t" << sizeof(unsigned int) << " bite\t" << "[0;294 967 295]" << std::endl;
    std::cout << "long:\t" << sizeof(long) << " bite\t" << "[-2 147 483 648;2 147 483 647]" << std::endl;
    std::cout << "unsigned long:\t" << sizeof(unsigned long) << " bite\t" << "[0;4 294 967 295]" << std::endl;
    std::cout << "long long:\t" << sizeof(long long) << " bite\t" << "[-9 223 372 036 854 775 808;9 223 372 036 854 775 807]" << std::endl;
    std::cout << "unsigned long long:\t" << sizeof(unsigned long long) << " bite\t" << "[0;18 446 744 073 709 551 615]" << std::endl;

    std::cout << "REAL TYPES:" << std::endl;
    std::cout << "float:\t" << sizeof(float) << " bite\t" << "[-3.4E-38;3.4E+38]\t" << "6-7 digits" << std::endl;
    std::cout << "double:\t" << sizeof(double) << " bite\t" << "[-1.7E-308;1.7E+308]\t" << "15-16 digits" << std::endl;
    std::cout << "long double:\t" << sizeof(long double) << " bite\t" << "[-1.7E-308;1.7E+308]\t" << "18-19 digits" << std::endl;

    std::cout << "CHARACTER TYPES:" << std::endl;
    std::cout << "char:\t" << sizeof(char) << " bite\t" << "[-127;128] or [0;255]" << std::endl;
    std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bite\t" << "[0;65 535]" << std::endl;
    std::cout << "char8_t:\t" << "1 bite\t" << "[0;256]" << std::endl;
    std::cout << "char16_t:\t" << sizeof(char16_t) << " bite\t" << "[0;65 535]" << std::endl;
    std::cout << "char32_t:\t" << sizeof(char32_t) << " bite\t" << "[0;4 294 967 295]\n" << std::endl;

    std::cout << "\t\tTask 2" << std::endl;
    std::cout << "INTEGER TYPE:" << std::endl;
    int a = 10;
    int b = 5;
    std::cout << "first number: " << a << "\t" << "second number: " << b << std::endl;
    std::cout << "first + second\t" << "== " << a + b << std::endl;
    std::cout << "first - second\t" << "== " << a - b << std::endl;
    std::cout << "first * second\t" << "== " << a * b << std::endl;
    std::cout << "first / second\t" << "== " << a / b << "\n" << std::endl;

    std::cout << "REAL TYPE:" << std::endl;
    float c = 2.5;
    float d = 1.5;
    std::cout << "first number: " << c << "\t" << "second number: " << d << std::endl;
    std::cout << "first + second\t" << "== " << c + d << std::endl;
    std::cout << "first - second\t" << "== " << c - d << std::endl;
    std::cout << "first * second\t" << "== " << a * b << std::endl;
    std::cout << "first / second\t" << "== " << a / b << "\n" << std::endl;

    std::cout << "CHARACTER TYPE:" << std::endl;
    char v = 'a';
    char w = 'b';
    std::cout << "first letter: " << v << "\t" << "second letter: " << w << std::endl;
    std::cout << "first + second\t" << "== " << v + w << std::endl;
    std::cout << "first - second\t" << "== " << v - w << std::endl;
    std::cout << "first * second\t" << "== " << v * w << std::endl;
    std::cout << "first / second\t" << "== " << v / w << "\n" << std::endl;

    std::cout << "LOGICAL TYPE:" << std::endl;
    bool t = true;
    bool f = false;
    std::cout << "first meaning: " << "true" << "\t" << "second meaning: " << "false" << std::endl;
    std::cout << "first + second\t" << "== " << t + f << std::endl;
    std::cout << "first - second\t" << "== " << t - f << std::endl;
    std::cout << "first * second\t" << "== " << t * f << std::endl;
    std::cout << "first / second\t" << "== " << "NaN" << "\n" << std::endl;
    return 0;
}


