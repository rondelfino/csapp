#include <stdio.h>

/* Returns 0 when x = INT_MIN */
int A(int x, int y)
{
  return (x < y) == (-x > -y);
}

/*
 * x << 4 + y << 4 + y - x -> (x << 4) - x + (y << 4) + y
 * (x << 4) - (x << 0) + (y << 4) + (y << 0) -> x * (16 - 1) + y * (16 + 1)
 * Therefore, always returns 1
 */
int B(int x, int y)
{
  return ((x + y) << 4) + y-x == 17*y + 15*x;
}

/*
 * ~k = -k - 1
 * -x - 1 + -y - 1 + 1 == ~(x + y)
 * -x - y -2 + 1 == ~(x + y)
 * -x - y - 1 == ~(x + y)
 * -(x + y) - 1 == ~(x + y)
 * Let x + y = z
 * -z -1 == ~(x + y)
 * ~z == ~(x + y)
 * ~(x + y) == ~(x + y)
 * Therefore, always returns 1
 */

int C(int x, int y)
{
  return ~x + ~y + 1 == ~(x + y);
}

/* 
 * (ux - uy) = -uy + ux
 * -(y - x) = -y + x => (unsigned)(-y + x) -> -uy + ux
 * Therefore, always returns 1
 */
int D(int x, int y)
{
  unsigned ux = (unsigned)x;
  unsigned uy = (unsigned)y;

  return (ux - uy) == -(unsigned)(y - x);
}

/*
 * (x >> 2) >> (2 >> 2) => (x >> 2) >> 0 => (x >> 2)/1 => x >> 2
 * x >> 2 <= x 
 * Therefore, always returns 1
 */
int E(int x, int y)
{
  return ((x >> 2) << 2) <= x;
}

int main(void)
{
  printf("%08x\n", ~5);
  printf("%08x\n", -5 - 1);

  return 0;
}
