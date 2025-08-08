#include <iostream>
#include <omp.h>

int main() {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            std::cout << "Section 1 executed by thread " << omp_get_thread_num() << std::endl;
        }
        
        #pragma omp section
        {
            std::cout << "Section 2 executed by thread " << omp_get_thread_num() << std::endl;
        }
        
        #pragma omp section
        {
            std::cout << "Section 3 executed by thread " << omp_get_thread_num() << std::endl;
        }
    }

    return 0;
}