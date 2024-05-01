#include <stdio.h>
#include <limits.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y)
{
  int sum = x + y;
  int pos_overflow = !(x & INT_MIN) && !(y & INT_MIN) && (sum & INT_MIN);
  int neg_overflow = (x & INT_MIN) && (y & INT_MIN) && !(sum & INT_MIN);

  pos_overflow && (sum = INT_MAX) || neg_overflow && (sum = INT_MIN);

  return sum;
}

int main(void)
{
  printf("%d\n", saturating_add(INT_MAX, 1));
  
  return 0;
}
