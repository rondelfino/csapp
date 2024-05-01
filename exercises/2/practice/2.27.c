#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y)
{
  unsigned sum = x + y;
  return sum >= x;
}

int main(void)
{
  printf("Overflow: %u\n", uadd_ok(5, 10));
  printf("Overflow: %u\n", uadd_ok(0, UINT_MAX));
  printf("Overflow: %u\n", uadd_ok(UINT_MAX, UINT_MAX));
}
