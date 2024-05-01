#include <stdio.h>

int bad_int_size_is_32()
{
  int set_msb = 1 << 31;
  int beyond_msb = set_msb << 1;

  return set_msb && !beyond_msb;
}

int bad_int_size_is_16()
{
  int set_msb = 1 << 15;
  int beyond_msb = set_msb << 1;
  
  printf("%d\n", beyond_msb);
  return set_msb && !beyond_msb;
}

int main(void)
{
  printf("%d\n", bad_int_size_is_16());
  printf("%d\n", bad_int_size_is_32());
  return 0;
}
