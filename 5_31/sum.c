// 输入正整数 n ，输出1+2+3...+n 的值。提示：目标时解决问题，不是编程

#include <stdio.h>

int main()
{
  int num = 0;
  int i =0;
  scanf("%d",&num);

  int ret = 0;
  for( i = 0; i <= num; ++i)
  {
    ret += i;
  }

  printf("%d\n", ret);

  return 0;
}
