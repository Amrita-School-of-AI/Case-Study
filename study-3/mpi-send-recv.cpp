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

    // Handle the case where there are less than 2 processes
    if (world_size < 2)
    {
        std::cerr << "This program requires at least two processes." << std::endl;
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // Prepare data to send
    int data;

    if (world_rank == 0)
    {
        data = 42; // Example data to send
        std::cout << "Process " << world_rank << " sending data: " << data << std::endl;
        // Send data to process 1
        // MPI_Send(buffer, count, MPI_Datatype, dest_rank, tag, communicator)
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    }
    else if (world_rank == 1)
    {
        // Receive data from process 0
        // MPI_Recv(buffer, count, MPI_Datatype, source_rank, tag, communicator, status)
        MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        std::cout << "Process " << world_rank << " received data: " << data << std::endl;
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}