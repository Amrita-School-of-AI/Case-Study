#include <iostream>
#include <mpi.h>

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    int world_size;
    int world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int data;
    if (world_rank == 0)
    {
        // Process 0 initializes the data
        data = 42; // Example data to broadcast
        std::cout << "Process 0 broadcasting data: " << data << std::endl;
    }

    // Broadcast the data from process 0 to all other processes
    // MPI_Bcast(buffer, count, MPI_Datatype, root, communicator)
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Print the received data in all processes
    std::cout << "Process " << world_rank << " received data: " << data << std::endl;

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}