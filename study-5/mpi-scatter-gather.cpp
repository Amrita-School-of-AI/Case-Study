#include <iostream>
#include <mpi.h>
#include <vector>

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

    int size = 12; // Size of the data array
    std::vector<int> data(size);

    // Initialize the data array only on the root process
    if (world_rank == 0)
    {
        for (int i = 0; i < size; ++i)
        {
            data[i] = i + 1; // Fill with some values
        }
        // Print the data on the root process
        std::cout << "Root process initialized data: ";
        for (const auto &value : data)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // Define a buffer to hold the scattered data
    int local_size = size / world_size; // Size of data each process will receive

    std::vector<int> local_data(local_size);

    // Scatter the data from the root process to all processes
    // MPI_Scatter(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm)
    MPI_Scatter(data.data(), local_size, MPI_INT, local_data.data(), local_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Print the local data received by each process
    std::cout << "Process " << world_rank << " received data: ";

    for (int i = 0; i < local_size; ++i)
    {
        std::cout << local_data[i] << " ";
    }

    std::cout << std::endl;

    // Multiply 2 each element of the local data
    for (int i = 0; i < local_size; ++i)
    {
        local_data[i] *= 2;
    }

    // Gather the modified data back to the root process
    // MPI_Gather(sendbuf, sendcount, sendtype, recvbuf, recvcount, recvtype, root, comm)
    MPI_Gather(local_data.data(), local_size, MPI_INT, data.data(), local_size, MPI_INT, 0, MPI_COMM_WORLD);

    // Print the gathered data on the root process
    if (world_rank == 0)
    {
        std::cout << "Root process gathered data: ";
        for (const auto &value : data)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // Finalize the MPI environment
    MPI_Finalize();
}