#include <iostream>
#include <mpi.h>

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Handle the case where there are fewer than 2 processes
    if (world_size < 2)
    {
        std::cerr << "This program requires at least two processes." << std::endl;
        MPI_Abort(MPI_COMM_WORLD, 1);
        return 1;
    }
    int message;
    int TAG = 0;
    if (world_rank == 0)
    {

        // Prepare a message to send
        message = 10;
        // MPI_Send(buffer, count, MPI_Datatype, dest, tag, comm)
        MPI_Send(&message, 1, MPI_INT, 1, TAG, MPI_COMM_WORLD);
    }
    else if (world_rank == 1)
    {
        // MPI_Recv(buffer, count, MPI_Datatype, source, tag, comm, status)
        MPI_Recv(&message, 1, MPI_INT, 0, TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        std::cout << "Process 1 received message: " << message << std::endl;
    }

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}