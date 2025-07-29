#include <iostream>

int main()
{
    int a = 65;
    char b = 'A';

    std::cout << "Integer: " << a << std::endl;
    std::cout << "Character: " << b << std::endl;
    std::cout << "Size of int: " << sizeof(a) << " bytes" << std::endl;
    std::cout << "Size of char: " << sizeof(b) << " bytes" << std::endl;

    int c = 'A';
    char d = 65;

    std::cout << "Character from int: " << c << std::endl;
    std::cout << "Int from character: " << d << std::endl;
    std::cout << "Size of int from char: " << sizeof(c) << " bytes" << std::endl;
    std::cout << "Size of char from int: " << sizeof(d) << " bytes" << std::endl;
    return 0;
}