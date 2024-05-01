#include <stdio.h>
#include <assert.h>

/* A. The function does not correctly sign extend if the byte is negative */

/* Declaration of data type where 4 bytes are packed
 * into an unsigned */
typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum)
{
  int max_bytenum = 3;
  return (int)(word << ((max_bytenum - bytenum) << 3)) >> (max_bytenum << 3);
}

int main(void)
{
  xbyte(0x81234567, 3);
  return 0;
}
