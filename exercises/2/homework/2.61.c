#include <stdio.h>
#include <limits.h>

/*
 * Returns 1 when the following conditions are true and 0 when they are false
 * A. Any bit of x equals 1
 * B. Any bit of x equals 0
 * C. Any bit in the least significant byte of x equals 1.
 * D. Any bit in the most significant byte of x equals 0.
 */

int main(void)
{
  int shift_val = (sizeof(int) - 1) << 3;
  int x = -1;
  int a = x && 1;
  int b = ~x && 1;
  int c = !(x & 0xFFu ^ 0xFFu); 
  int d = !((x >> shift_val) & 0xFFu);
  printf("w: %d\n", shift_val);
  printf("a: %d\n", a);
  printf("b: %d\n", b);
  printf("c: %d\n", c);
  printf("d: %x\n", d);
  return 0;
}
