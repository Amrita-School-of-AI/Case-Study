#include <iostream>
#include <vector>
#include <numeric>
#include <omp.h>

int main()
{
    int n = 1000;
    std::vector<int> vec(n, 1); // Initialize a vector of size n with all elements set to 1
    long long total_sum = 0;

#pragma omp parallel for reduction(+ : total_sum)
    for (int i = 0; i < n; ++i)
    {
        total_sum += vec[i];
    }

    std::cout << "Total sum: " << total_sum << std::endl;
    return 0;
}