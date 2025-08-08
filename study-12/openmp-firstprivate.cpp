#include<iostream>
#include<omp.h>

int main() {
    int val = 50;

    // Print the value before parallel region
    std::cout << "Before parallel region, val = " << val << std::endl;
    

#pragma omp parallel firstprivate(val)
    {
        // val is initialized to 50 for each thread
        int thread_id = omp_get_thread_num();
        val += thread_id; // Each thread modifies its own copy of val
#pragma omp critical    
        {
            // Print the value of val for each thread
            // This ensures that the output is not interleaved
            std::cout << "Thread " << thread_id << " modifies val to " << val << std::endl;
        }
    }

    // Print the value after parallel region
    std::cout << "After parallel region, val = " << val << std::endl;
    return 0;
}