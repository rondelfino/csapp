#include <corecrt_memory.h>
#include <stdio.h>

/* 
 * A. The conditional test always succeeds in the original buggy code
 * because the sizeof() operator returns a size_t, which is a typedef for unsigned.
 * Therefore the subtraction operation will coerce its other operand, maxbytes, to size_t,
 * thus returning a size_t. Since unsigned values can never be less than 0, the conditional
 * test is always true; arithmetic is modular, so the result would be maxbytes - sizeof(val) + 2^32.
*/

/* Copy integer into buffer if space is available */
void copy_int(int val, void *buf, int maxbytes)
{
  if (maxbytes - (int)sizeof(val) >= 0)
  {
    memcpy(buf, (void *) &val, sizeof(val));
  }
  else
    printf("%u\n", maxbytes - sizeof(val));
}

int main(void)
{
  void *buffer;
  copy_int(5, &buffer, 3);
  return 0;
}
