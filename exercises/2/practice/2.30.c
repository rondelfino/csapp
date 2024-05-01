#include <stdio.h>
#include <limits.h>

int tadd_ok(int x, int y)
{
  int sum = x + y;
  int pos_over = x >= 0 && y >= 0 && sum < 0;
  int neg_over = x < 0 && y < 0 && sum >= 0;
  return !pos_over && !neg_over;
}

int tsub_ok(int x, int y)
{
  return tadd_ok(x, -y);
}

int main(void)
{
  // printf("Overflow: %d\n", tadd_ok(INT_MAX, 0));
  printf("Add overflow: %d\n", tadd_ok(INT_MIN, -2));
  // printf("Overflow: %d\n", tadd_ok(5, -2));
  // printf("Overflow: %d\n", tadd_ok(-9, -2));
  
  printf("Sub overflow: %d\n", tsub_ok(INT_MIN, -2));
  
  return 0;
}
