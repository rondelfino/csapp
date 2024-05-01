#include <stdio.h>
#include <stdlib.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)                                                   \
  ((byte) & 0x80 ? '1' : '0'), ((byte) & 0x40 ? '1' : '0'),                    \
      ((byte) & 0x20 ? '1' : '0'), ((byte) & 0x10 ? '1' : '0'),                \
      ((byte) & 0x08 ? '1' : '0'), ((byte) & 0x04 ? '1' : '0'),                \
      ((byte) & 0x02 ? '1' : '0'), ((byte) & 0x01 ? '1' : '0')

char *get_asdf_string_2() {
  char a[5];
  a[0] = 'a';
  a[1] = 's';
  a[2] = 'd';
  a[3] = 'f';
  a[4] = '\0';
  return a;
}

char *get_asdf_string_1() {
  char *a = "asdf";
  return a;
}

char *get_asdf_string_3() {
  char *a = malloc(sizeof(char) * 5);
  a = "asdf";
  return a;
}

char *g = "asdf";
char *get_asdf_string_4() { return g; }

int main(void) {
  char *test = get_asdf_string_4();
  printf("%s\n", test);
  return 0;
}
