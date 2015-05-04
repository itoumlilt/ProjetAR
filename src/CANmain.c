#include <CAN.h>
#include <CANinsertData.h>
#include <CANsearchData.h>
#include <display.h>


int main(int argc, char** argv)
{
  int ret = 0;
  MPI_Init(&argc, &argv);

  /* init */
  CANinitialize();

  /* myId */
  int myId, nbProcess;
  MPI_Comm_rank(MPI_COMM_WORLD, &myId);
  MPI_Comm_size(MPI_COMM_WORLD, &nbProcess);

  srand((unsigned)time(NULL)+getpid()*myId+nbProcess);

  /* insert */
  CANinsert();

  printf("Post-Insert\n");

  while(1){
    CANhandleMessage();
  }

  MPI_Finalize();
  return ret;
}
