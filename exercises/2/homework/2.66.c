#include <stdio.h>

int leftmost_one(unsigned x)
{
  int w = sizeof(int) << 3;
  x |= x >> 16;
  x |= x >> 8;
  x |= x >> 4;
  x |= x >> 2;
  x |= x >> 1;
  x -= (x >> 1);
  
  return x;
}

int main(void)
{
  printf("%08x\n", leftmost_one(0x053dF001));
  return 0;
}
