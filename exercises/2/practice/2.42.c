#include <stdio.h>

int div16(int x)
{
  int bias = (1 << 4) - 1;
  printf("%d\n", bias);
  return (x + bias) >> 4;
}

int main(void)
{
  div16(12340);
  
  return 0;
}

