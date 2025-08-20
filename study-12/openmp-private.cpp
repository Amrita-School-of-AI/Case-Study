#include <iostream>
#include <omp.h>

int main()
{
    int var = 50;

    // Print the initial value of var
    std::cout << "Initial value of var: " << var << std::endl;

#pragma omp parallel private(var)
    {
        // Each thread gets its own copy of var
        var = omp_get_thread_num();

// Print the value of private_var in each thread
#pragma omp critical
        std::cout << "Thread " << omp_get_thread_num()
                  << " has private_var: " << var << std::endl;
    }

    // Print the final value of private_var
    std::cout << "Final value of private_var: " << var << std::endl;

    return 0;
}