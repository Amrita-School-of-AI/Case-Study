#include <iostream>
#include <omp.h>
#include <vector>

int main()
{
    int total_sum = 0;
    int n = 1000;
    std::vector<int> data(n, 1);

#pragma omp parallel for shared(total_sum, data)
    for (int i = 0; i < n; i++)
    {
        total_sum += data[i];
    }

    std::cout << "Total sum: " << total_sum << std::endl;
    return 0;
}