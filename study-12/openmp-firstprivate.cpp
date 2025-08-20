#include <iostream>
#include <omp.h>

int main()
{
    int var = 50;

    // Print the initial value of var
    std::cout << "Initial value of var: " << var << std::endl;

#pragma omp parallel firstprivate(var)
    {
        //
        int thread_id = omp_get_thread_num();

        // Each thread gets its own copy of var initialized to the value of var at the start
        var += thread_id;
// Print the value of var in each thread
#pragma omp critical
        std::cout << "Thread " << omp_get_thread_num()
                  << " has var: " << var << std::endl;
    }

    // Print the final value of var
    std::cout << "Final value of var: " << var << std::endl;
    return 0;
}