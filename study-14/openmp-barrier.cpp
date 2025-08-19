#include <iostream>
#include <omp.h>
#include <vector>

int main()
{
    int num_threads = 4;
    std::vector<int> data(num_threads);

#pragma omp parallel num_threads(num_threads)
    {
        int thread_id = omp_get_thread_num();

        // Stage1: Each thread will write its own own data to the vector
        data[thread_id] = thread_id * 10;
        std::cout << "Thread " << thread_id << " wrote: " << data[thread_id] << std::endl;

#pragma omp barrier // Ensure all threads have written their data before proceeding

// Stage 2: Each thread reads the data safely
#pragma omp master
        {
            for (int i = 0; i < num_threads; i++)
            {
                std::cout << "Thread " << thread_id << " reads data[" << i << "] = " << data[i] << std::endl;
            }
        }
    }

    return 0;
}