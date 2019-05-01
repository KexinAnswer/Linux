#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define RED "\e[0;31m"
#define GREEN "\e[0;32m" 
#define YELLOW "\e[1;33m"
#define NONE "\e[0m"

int main()
{
  char str[100] = {0};
  char *loading = "-\\|/";
  memset(str,' ',100);
  int i = 0;
  for(; i<100; ++i)
  {
    str[i] = '#';
    if(i < 33)
    {
      printf(GREEN"[%s][%d%%][%c]\r"NONE,str,i,loading[i%4]);
    }
    else if(i>= 33 && i< 66)
    {
      printf(YELLOW"[%s][%d%%][%c]\r"NONE,str,i,loading[i%4]);

    }
    else
    {
      printf(RED"[%s][%d%%][%c]\r"NONE,str,i,loading[i%4]);

    }
    fflush(stdout);
    usleep(300 * 1000);

  }
  printf("\n完成！\n");
  return 0;
} 



