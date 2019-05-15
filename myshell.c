#include <stdio.h>

int split(char input[], int n)
{
  (void) n;

}
int main()
{
  char argv[1024];
  while(1)
  {
    int count = 0;
    //打印用户名，主机名，文件目录
    printf("[myshell@local ~]");
    fflush(stdout);

    //获取命令
    char input[1024];
    gets(input);

    int n = split(input, count);
  }
  
  return 0;
}
