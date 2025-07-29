// A simple example to demonstrate MPI Reduce operation with local errors computed as sum of least squares into a global error variable.

#include <iostream>
#include <cmath>
#include <mpi.h>
#include <vector>

int main(int argc, char **argv)
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    int world_size;
    int world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // 1. Each process computes its local error
    double local_error = world_rank + 1; // Example local error, can be any computation
    double local_error_squared = local_error * local_error;

    // 2. Reduce operation to compute the global error as the sum of local errors squared
    double global_error_squared = 0.0;

    // MPI_Reduce(sendbuf, recvbuf, count, datatype, op, root, comm)
    MPI_Reduce(&local_error_squared, &global_error_squared, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // 3. The root process (rank 0) will print the global error
    if (world_rank == 0)
    {
        double global_error = std::sqrt(global_error_squared);
        std::cout << "Global error (sum of least squares): " << global_error << std::endl;
    }

    // Finalize the MPI environment
    MPI_Finalize();

    return 0;
}