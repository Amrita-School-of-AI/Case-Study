#include <iostream>
#include <omp.h>

int main()
{
    int private_var = 50;

    // Print the value before parrallel region
    std::cout << "Before parallel region, private_var = " << private_var << std::endl;

#pragma omp parallel private(private_var)
    {
        // private_var is not defined
        int thread_id = omp_get_thread_num();
        private_var += thread_id; // Each thread gets its own copy of private_var
#pragma omp critical
        {
            // Print the value of private_var for each thread
            // This ensures that the output is not interleaved
            std::cout << "Thread " << thread_id << " sets private_var = " << private_var << std::endl;
        }
    }

    // Print the value after parallel region
    std::cout << "After parallel region, private_var = " << private_var << std::endl;
    return 0;
}