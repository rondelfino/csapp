#include <stdio.h>
#include <assert.h>

/* 
 * Write expressions to generate the bit patterns that follow, where a^k represents
 * k repretitions of symbol a. Assume a w-bit data type. Your code may contain references
 * to parameters j and k, representing the values of j and k, but not a parameter representing w
 */
int A(int k)
{
  return -1 << k;
}

int B(int k, int j)
{
  // int x = -1;
  // x = (x << j) ^ (x << (k + j));
  // return x;

  return ~A(k) << j;
}

int main(void)
{
  assert(A(8) == 0xFFFFFF00);
  assert(B(16, 8) == 0x00FFFF00);
  return 0;
}

