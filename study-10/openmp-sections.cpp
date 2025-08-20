#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel num_threads(4)
    {
#pragma omp sections
        {
#pragma omp section
            {
#pragma omp critical
                {
                    std::cout << "Thread no: " << omp_get_thread_num() << " executing section 0" << std::endl;
                }
            }
#pragma omp section
            {
#pragma omp critical
                {
                    std::cout << "Thread no: " << omp_get_thread_num() << " executing section 2" << std::endl;
                }
            }
#pragma omp section
            {
#pragma omp critical
                {
                    std::cout << "Thread no: " << omp_get_thread_num() << " executing section 3" << std::endl;
                }
            }
        }
    }
    return 0;
}