#include <iostream>
#include <omp.h>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> reports;

#pragma omp parallel num_threads(4)
    {
        int thread_id = omp_get_thread_num();
        std::string report = "Report from thread " + std::to_string(thread_id);

// Only one thread can execute this block at a time
#pragma omp critical
        {
            reports.push_back(report);
        }
    }

    std::cout << "Collected Reports:\n";
    for (const auto &report : reports)
    {
        std::cout << report << std::endl;
    }
    return 0;
}