#include <iostream>
#include <omp.h>
#include <vector>

int main()
{
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

#pragma omp parallel for ordered
    for (int i = 0; i < data.size(); ++i)
    {
        // Threads can do it this in any order, but output must be ordered
        int result = data[i] * 2;

#pragma omp ordered
        {
            std::cout << "Thread " << omp_get_thread_num()
                      << " processed data[" << i << "] = " << result << std::endl;
        }
    }

    std::cout << "All threads have completed processing." << std::endl;
    return 0;
}