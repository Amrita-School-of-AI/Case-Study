#include <iostream>
#include <mpi.h>

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    int world_rank;
    int world_size;

    // Get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Prepare data to be broadcasted
    int data;
    if (world_rank == 0)
    {
        data = 42; // Root process initializes the data
    }
    else
    {
        data = 0; // Other processes will receive this value
    }

    // Broadcast the data from the root process (rank 0) to all other processes
    // MPI_Bcast(buffer, count, MPI_Datatype, root, communicator)
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Each process prints the received data 
    std::cout << "Process " << world_rank << " received data: " << data << std::endl;

    // Finalize the MPI environment
    MPI_Finalize();
}