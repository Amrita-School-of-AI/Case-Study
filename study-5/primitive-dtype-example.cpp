#include <iostream>

int main()
{
    int a = 65;
    float b = 3.14;
    char c = 'A';

    std::cout << "Integer: " << a << std::endl;
    std::cout << "Float: " << b << std::endl;
    std::cout << "Character: " << c << std::endl;

    int a1 = 'A';
    char c1 = 65;

    std::cout << "Integer from char: " << a1 << std::endl;
    std::cout << "Character from integer: " << c1 << std::endl;

    return 0;
}