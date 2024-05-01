#include <stdint.h>
#include <assert.h>
#include <stdio.h>

int signed_high_prod(int x, int y)
{
  int64_t prod = (int64_t)x * y;
  return prod >> 32;
}

unsigned unsigned_high_prod(unsigned x, unsigned y)
{
  int w = sizeof(int) << 3;
  int sign_x = x >> (w - 1);
  int sign_y = y >> (w - 1);
  int signed_prod = signed_high_prod(x, y);
  return signed_prod + (x * sign_y + y * sign_x);
}

unsigned test(unsigned x, unsigned y)
{
  uint64_t prod = (uint64_t)x * y;
  return prod >> 32;
}

int main(void)
{
  unsigned x = 0xFFFFFFFF;
  unsigned y = 0x12345678;
  assert(unsigned_high_prod(x, y) == test(x, y));
  printf("%016x\n", unsigned_high_prod(x, y));
  printf("%016llx\n", (uint64_t)(x * y));
  printf("%016x\n", test(x, y));
  return 0;
}
