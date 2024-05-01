#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* Compute 3*x/4 */
int mul3div4(int x)
{
  int w = sizeof(int) << 3;
  int bias = 0;
  (x >> (w - 4) & 0xF) && (bias = (1 << 2) - 1);
  x = (x << 2) - x;
  return (x + bias) >> 2;
}

int main(void)
{
  int x = INT_MIN;
  assert(mul3div4(x) == x * 3 / 4);  
  // printf("%d\n", mul3div4(INT_MIN));
  
  return 0;
}
