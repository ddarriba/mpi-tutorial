/* Example 02: Point to point messages
 *
 * This example introduces point to point messages.
 */

#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
  int numprocs, rank, number;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  if (rank == 0)
  {
    number = 42;
    for (int i=1; i<numprocs; ++i)
      MPI_Send(&number,         // buffer
               1,               // count
               MPI_INT,         // datatype
               i,               // target
               457,             // tag
               MPI_COMM_WORLD); // communicator
  }
  else
  {
    printf("Process %d/%d: number = %d (before)\n", rank, numprocs, number);
    MPI_Recv(&number,         // buffer
             1,               // count
             MPI_INT,         // datatype
             0,               // source
             457,             // tag
             MPI_COMM_WORLD,  // communicator
             &status);
    printf("Process %d/%d number = %d (after)\n", rank, numprocs, number);
  }

  MPI_Finalize();
}
