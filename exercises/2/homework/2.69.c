#include <stdio.h>
#include <assert.h>

/*
 * Do rotating left shift. Assume <= n < w
 * Examples when x = 0x12345678 and w = 32:
 *    n=4 -> 0x23456781, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n)
{
  int w = sizeof(int) << 3;
  int y = (x << n);
  int z = (x >> (w - n));
  int result = y | z;
  
  return result;
}

int main(void)
{
  printf("%08x\n", rotate_left(0x12345678, 0));

  assert(rotate_left(0x12345678, 4) == 0x23456781);
  assert(rotate_left(0x12345678, 20) == 0x67812345);
  assert(rotate_left(0x12345678, 0) == 0x12345678);
  return 0;
}
