#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < 10; ++i)
        {
#pragma omp critical
            {
                std::cout << "Thread no: " << omp_get_thread_num() << " processing iteration " << i << std::endl;
            }
        }
    }

    return 0;
}