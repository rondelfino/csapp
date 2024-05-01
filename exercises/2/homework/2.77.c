#include <stdio.h>

/* 
 * Calculate the product x * k efficiently using only <<, +, -, 
 * and at most 3 operations per expression 
*/
int A(int x)
{
  int k = 17;
  return (x << 4) + x;
}

int B(int x)
{
  int k = -7;
  return -(x << 3) + x;
}

int C(int x)
{
  int k = 60;
  return (x << 6) - (x << 2);
}

int D(int x)
{
  int k = -112;
  return -(x << 7) + (x << 4);
}

int main(void)
{
  printf("%d\n", A(2));
  printf("%d\n", B(2));
  printf("%d\n", C(2));
  printf("%d\n", D(2));

  return 0;
}
