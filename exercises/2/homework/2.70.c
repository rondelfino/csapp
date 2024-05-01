#include <stdio.h>
#include <assert.h>
#include <limits.h>

/*
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */
int fits_bits(int x, int n)
{
  int w = sizeof(int) << 3;
  int mask = (unsigned)-1 >> (w - (n - 1));
  
  return (x & mask) == x;
}

int main(void)
{
  // fits_bits(0x6, 3);
  
  // assert(!fits_bits(0xFF, 8));
  // assert(!fits_bits(~0xFF, 8));

  // assert(fits_bits(0b0010, 3));
  // assert(!fits_bits(0xA, 3));
  // assert(!fits_bits(0x6, 3));

  // assert(fits_bits(~0b11, 3));
  // assert(!fits_bits(~0b01000011, 3));
  // assert(!fits_bits(~0b111, 3));  
  return 0;
}
