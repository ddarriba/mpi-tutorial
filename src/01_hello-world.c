/* Example 01: Hello world
 *
 * This minimal example contains the essential MPI calls in every parallel
 * program.
 */

#include <stdio.h>

/* 1. Include MPI header */
#include <mpi.h>

int main(int argc, char *argv[])
{
  int numprocs, rank;

  /* 2. Initialize MPI environment */
  MPI_Init(&argc, &argv);

  /* 3. Get the number of processes running in parallel.
   *    `numprocs` will be set to the number of processes requested when you
   *    ran `mpirun -n NUMPROCS bin/01-hello-world`.
   */
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  /* 4. Get the process rank.
   *    Each process has a unique rank, ranging from 0 to (numprocs - 1).
   *    We use `rank` such that each process performs different operations.
   */
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  printf("Hi from process %d out of %d\n", rank, numprocs);

  /* 5. Finalize MPI environment
   *    All processes must call this before exiting, and it guarantees that all
   *    of them reach this point before finishing the execution.
   *
   *    After this call, the processes are not linked together anymore, and any
   *    process can finish the execution without killing the others.
   */
  MPI_Finalize();

  return 0;
}
