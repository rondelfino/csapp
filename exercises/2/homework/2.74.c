#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* Determine whether arguments can be subtracted without overflow */
int tsub_ok(int x, int y)
{
  int result = 1;
  /* If y is INT_MIN it will always result in an overflow */
  /* -INT_MIN is undefined behavior because INT_MIN cannot be represented as a positive number */ 
  int different_signs = !((x ^ y) & INT_MIN);
  int overflow = ((x - y) ^ x) & ((x - y) ^ y);
  ((y == INT_MIN) || (different_signs && overflow)) && (result = 0);

  return result;
}

int main(void)
{
  
  tsub_ok(2, -1);


  assert(!tsub_ok(0x00, INT_MIN));
  assert(tsub_ok(0x00, 0x00));  
  return 0;
}
