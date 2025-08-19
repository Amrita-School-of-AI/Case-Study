#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel num_threads(4)
    {
#pragma omp master
        {
            std::cout << "Hello from thread " << omp_get_thread_num() << std::endl;
        }

// All threads has to wait here until the master thread has executed
#pragma omp barrier

#pragma omp critical
        {
            std::cout << "Hello from thread " << omp_get_thread_num() << std::endl;
        }

#pragma omp barrier

#pragma omp single
        {
            std::cout << "This is a single section executed by one thread with thread id " << omp_get_thread_num() << std::endl;
        }
    }

    return 0;
}