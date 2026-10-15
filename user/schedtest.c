
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(void)
{
  for(int i = 0; i < 3; i++) {
    int pid = fork();

    if(pid == 0) {
      int x = 0;

      for(int j = 0; j < 10000000; j++)
        x++;

      printf("Process %d finished, x=%d\n", getpid(), x);
      exit(0);
    }
  }

  for(int i = 0; i < 3; i++)
    wait(0);

  exit(0);
}
