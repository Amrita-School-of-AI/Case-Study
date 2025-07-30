// Demonstating MPI status usage in C++ with random buffer sizes

#include <iostream>
#include <mpi.h>
#include <unistd.h>
#include "mpi-status.h"

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    int world_size;
    int world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int volatile j = 1;
    while (j)
    sleep(5);

    const int MAX_BUFFER_SIZE = 64;
    int numbers[MAX_BUFFER_SIZE];
    int number_amount = 0;

    if (world_rank == 0)
    {

        // Pick a random number of elements to send
        number_amount = rand() % MAX_BUFFER_SIZE + 1; // Random size between 1 and MAX_BUFFER_SIZE
        for (int i = 0; i < number_amount; i++)
        {
            numbers[i] = i; // Fill the buffer with some data
        }
        // Send the actual data
        MPI_Send(numbers, number_amount, MPI_INT, 1, 0, MPI_COMM_WORLD);
        std::cout << "Process 0 sent " << number_amount << " numbers." << std::endl;
    }
    else if (world_rank == 1)
    {
        MPI_Status status;
        // Receive the data
        // MPI_Probe(source, tag, comm, status) is used to check for incoming messages
        MPI_Probe(0, 0, MPI_COMM_WORLD, &status);

        // Get the size of the incoming message
        MPI_Get_count(&status, MPI_INT, &number_amount);

        // Resize the buffer to fit the incoming data
        int *received_numbers = new int[number_amount];

        // Now receive the actual data
        MPI_Recv(received_numbers, number_amount, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        std::cout << "Process 1 received " << number_amount << " numbers: ";
        for (int i = 0; i < number_amount; i++)
        {
            std::cout << received_numbers[i] << " ";
        }
        std::cout << std::endl;

        delete[] received_numbers; // Clean up dynamically allocated memory
    }

    // Synchronize all processes before finalizing
    MPI_Barrier(MPI_COMM_WORLD);
    // Print a message from each process
    std::cout << "Process " << world_rank << " completed its task." << std::endl;

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}