#include <iostream>
#include <omp.h>

int main()
{
    int var = 50;

    std::cout << "Initial value of var: " << var << std::endl;

#pragma omp parallel for lastprivate(var)
    for (int i = 0; i < 100; i++)
    {
        var = i * 10;
    }

    std::cout << "Final value of var: " << var << std::endl;

    return 0;
}
