#include <stdio.h>
/* Return 1 when x contains an odd number of 1s; 0 ohterwise.
 * Assume w=32 */
int odd_ones(unsigned x)
{
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;
  return x & 1;
}

int main(void)
{
  printf("%d\n", odd_ones(0x8));
  return 0;
}
