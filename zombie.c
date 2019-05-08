#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  int i = 0;
  pid_t id = fork();
  if(id < 0)
  {
    perror("fork");
  }
  else if(id > 0)
  {
    //parent;
    printf("parent[%d] is sleeping ...",getpid());

    while(1)
    {

    sleep(5);
    }
  }
  else
  {
    //child
    printf("child[%d] begin Z ...", getpid());
   while(i < 5)
   {
     i++;
     sleep(5);
   }
  }

  return 0;
}
