#include <stdio.h>

/* Divide by power of 2. Assume 0 <= k < w - 1 */
int divide_power2(int x, int k)
{
  int w = sizeof(int) << 3;
  int bias = 0;
  ((x >> (w - 4)) & 0xF) && (bias = (1 << k) - 1);
  return (x + bias) >> k;
}

int main(void)
{
  printf("%d\n", divide_power2(-12343, 3));
}
