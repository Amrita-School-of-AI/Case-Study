#include <iostream>
#include <omp.h>

int main()
{
    int shared_counter = 0;
    int private_counter = 0;
    int lastprivate_counter = 50;
    int firstprivate_counter = 100;
    const int iterations = 1000;

    // print the values before the parallel region

    std::cout << "Before parallel region:" << std::endl;
    std::cout << "Shared counter: " << shared_counter << std::endl;
    std::cout << "Private counter: " << private_counter << std::endl;
    std::cout << "Lastprivate counter: " << lastprivate_counter << std::endl;
    std::cout << "Firstprivate counter: " << firstprivate_counter << std::endl;
    std::cout << std::endl;

#pragma omp parallel
    {
        // print values in the parallel region
        std::cout << "In parallel region before for loop:" << std::endl;
        std::cout << "Shared counter: " << shared_counter << std::endl;
        std::cout << "Private counter: " << private_counter << std::endl;
        std::cout << "Lastprivate counter: " << lastprivate_counter << std::endl;
        std::cout << "Firstprivate counter: " << firstprivate_counter << std::endl;
        std::cout << std::endl;
#pragma omp parallel for shared(shared_counter) private(private_counter) lastprivate(lastprivate_counter) firstprivate(firstprivate_counter)

        for (int i = 0; i < iterations; ++i)
        {
            shared_counter++;
            private_counter++;
            lastprivate_counter++;
            firstprivate_counter++;
        }

        // print values after the for loop
        std::cout << "In parallel region after for loop:" << std::endl;
        std::cout << "Shared counter: " << shared_counter << std::endl;
        std::cout << "Private counter: " << private_counter << std::endl;
        std::cout << "Lastprivate counter: " << lastprivate_counter << std::endl;
        std::cout << "Firstprivate counter: " << firstprivate_counter << std::endl;
        std::cout << std::endl;
    }
    // print the values after the parallel region
    std::cout << "After parallel region:" << std::endl;
    std::cout << "Shared counter: " << shared_counter << std::endl;
    std::cout << "Private counter: " << private_counter << std::endl;
    std::cout << "Lastprivate counter: " << lastprivate_counter << std::endl;
    std::cout << "Firstprivate counter: " << firstprivate_counter << std::endl;
    std::cout << std::endl;

    return 0;
}