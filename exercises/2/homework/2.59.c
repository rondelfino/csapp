#include <stdio.h>

/* Creates a word consisting of the least significant byte of x and the
 * remaining bytes of y */

int main(void) {
  int x = 0x89ABCDEF;
  int y = 0x76543200;
  int res = (y ^ (y & 0xFF)) | x & 0xFF;

  printf("%x\n", res);
  return 0;
}
