#include <iostream>
#include <omp.h>

int main()
{
    int lastprivate_var = 0;

    std::cout << "Initial value of lastprivate_var: " << lastprivate_var << std::endl;

#pragma omp parallel for lastprivate(lastprivate_var)
    for (int i = 0; i < 100; i++)
    {
        lastprivate_var = i * 10;
    }

    std::cout << "Thread " << omp_get_thread_num()
              << " lastprivate_var: " << lastprivate_var << std::endl;

    std::cout << "Final value of lastprivate_var: " << lastprivate_var << std::endl;
    return 0;
}