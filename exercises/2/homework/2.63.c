#include <assert.h>
#include <limits.h>
#include <stdio.h>

/* Perform shift logically using given arithmetic right shift (xsra) */
/* TODO: Robust test cases */
unsigned srl(unsigned x, int k) {
  unsigned xsra = (int)x >> k;
  unsigned w = sizeof(int) << 3;

  int mask = (int)-1 << (w - k);
  int srl = (xsra | mask) ^ mask;

  return srl;
}

/* Perform shift arithmetically using given logical right shift (xsrl) */
int sra(int x, int k) {
  int xsrl = (unsigned)x >> k;
  unsigned w = sizeof(int) << 3;

  int mask = (int)-1 << (w - k);
  int msb = !(x & (int)-1 << (w - 1)) - 1;
  int sra = xsrl | ((~msb & mask) ^ mask);

  return sra;
}

int main(void) {
  int test_int = 0x1234ab1c;
  unsigned test_u = 0x8234ab1c;
  assert(srl(test_u, 4) == test_u >> 4);
  assert(sra(test_int, 16) == test_int >> 16);
  return 0;
}
