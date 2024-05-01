#include <stdio.h>

/* Return 1 when any odd bit of x equals 1; 0 otherwise.
 * Assume w=32 */
int any_odd_one(unsigned x)
{
  return !!(x & 0xAAAAAAAA);
}

int main(void) 
{ 
  printf("%d\n", any_odd_one(0xA));
  return 0; 
}
