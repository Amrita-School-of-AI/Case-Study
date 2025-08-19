#include <stdio.h>
#include <stdlib.h>

int factorial(int n)
{
    int result = 1;
    // Bug: loop should be i <=n
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

void process_data(int *data_ptr, int count)
{
    printf("Processing data at address %p\n", data_ptr);
    for (int i = 0; i < count; i++)
    {
        printf("Data item %d: %d, Factorial: %d\n", i, data_ptr[i], factorial(data_ptr[i]));
    }
}

int main()
{
    int data[] = {5, 4, 3, 2, 1};
    int *data_ptr = data;

    process_data(data_ptr, sizeof(data) / sizeof(data[0]));

    // Let's create a segmentation fault intentionally
    // data_ptr = NULL;

    process_data(data_ptr, 5); // This will cause a segmentation fault

    return 0;
}