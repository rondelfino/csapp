#include <stdio.h>

/* Replace a byte in a given position 
 * unsigned x: input word 
 * int i: byte position 
 * unsigned char b: byte to replace
 */
unsigned replace_byte(unsigned x, int i, unsigned char b) {
  int bits = i << 3;
  unsigned y = ((x >> bits) & 0xFF) << bits;
  unsigned result = x ^ y;
  result |= (b << bits);

  return result;
}

int main(void) {
  unsigned test = replace_byte(0x12345678, 0, 0xAB);
  printf("Result: %08x\n", test);
  test = replace_byte(0x12345678, 1, 0xAB);
  printf("Result: %08x\n", test);
  test = replace_byte(0x12345678, 2, 0xAB);
  printf("Result: %08x\n", test);
  test = replace_byte(0x12345678, 3, 0xAB);
  printf("Result: %08x\n", test);
  test = replace_byte(0x12345678, 4, 0xAB);
  printf("Result: %08x\n", test);
  return 0;
}
