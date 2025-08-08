#include <iostream>
#include <omp.h>

int main()
{
#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < 10; ++i)
        {
            std::cout << "Thread " << omp_get_thread_num() << " processing iteration " << i << std::endl;
        }
    }

    return 0;
}