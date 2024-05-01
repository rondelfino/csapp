#include <stdio.h>

/* Return 1 if little endian, otherwise return 0 */
int is_little_endian(void) {
  int test = 1;
  return test & 0x1;
}

int main(void) {
  printf("%d\n", is_little_endian());
  return 0;
}
