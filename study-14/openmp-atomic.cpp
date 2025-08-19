#include <iostream>
#include <omp.h>

int main()
{
    long long counter = 0;

#pragma omp parallel for
    for (int i = 0; i < 1000000; i++)
    {
// Each thread increments the counter
#pragma omp atomic
        counter++;
    }

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}