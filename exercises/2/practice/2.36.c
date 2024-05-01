#include <limits.h>
#include <stdio.h>
#include <stdint.h>

// Determine whether arguments can be multiplied without overflow
int tmult_ok(int x, int y)
{
  int64_t product = (int64_t) x*y;
  // If product changes when downcasting, an overflow occured 
  return product == (int) product;
}

int main(void)
{
  printf("Overflow: %d\n", tmult_ok(INT_MIN, INT_MIN));
  return 0;
}
