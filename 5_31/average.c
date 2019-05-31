//平均数
//输入3个整数，输出他们的平均值，保留3位小数
#include <stdio.h>

int main()
{
  int num1 = 0;
  int num2 = 0;
  int num3 = 0;

  scanf("%d %d %d", &num1, &num2, &num3);

  double ret = (num1 + num2 + num3) / 3;

  printf("%.3f\n", ret);

  return 0;
}
