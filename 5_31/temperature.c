//输入华氏温度 f ,输出对应的摄氏温度 c  ，保留3位小数。 提示：c = (f-32) /9 


#include <stdio.h>

int main()
{
  int f = 0;
  scanf("%d", &f);
  printf("c = (f-32) / 9");
  printf("当华氏温度 = %d 时，所对应的 摄氏温度 = %d \n", f, (f-32) / 9);

  return 0;
}
