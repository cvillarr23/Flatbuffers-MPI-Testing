#include <mpi.h>


#define HEARTBEAT 5.0

int main(int argc, char* argv[]) {
  MPI_Init(argc, argv);

  int rank, numRanks;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &numRanks);

  double time;
  double syncTime = 5.0;
while(true) {
  time = MPI_Wtime();
  if(time > syncTime) {
    syncTime += HEARTBEAT;
    MPI_Alltoall(const void *sendbuf, int sendcount, MPI_Datatype sendtype, void *recvbuf, int recvcount, MPI_Datatype recvtype, MPI_Comm comm)
  }

}



  return 0;
}
