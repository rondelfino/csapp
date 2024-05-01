#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* 
    Precision preservation: When dealing with integer arithmetic, \
    you need to be mindful of overflow. 
    If you were to directly multiply the entire x by 3 and then divide by 4, 
    the intermediate result after multiplication could exceed the 
    maximum representable value for an integer, leading to overflow 
    and loss of precision.

    Handling fractional parts: The fraction (3/4) implies that you're 
    dealing with parts of the number that are less than 1. 
    Splitting the number into two parts - one representing the most 
    significant bits and the other representing the least significant bits - allows you to handle the fractional part separately. 
    This is akin to separating the whole number part and the decimal part in decimal arithmetic.

    Avoiding rounding issues: By dividing the most significant bits 
    by 4 first, you ensure that any rounding that occurs in the division 
    process doesn't affect the least significant bits. 
    Similarly, by multiplying the least significant bits by 3 first, 
    you ensure that the multiplication doesn't cause overflow 
    or rounding issues when combined with the most significant bits.

    Correct handling of negative numbers: Splitting the number and processing 
    it separately allows you to handle negative numbers correctly. 
    You can apply different operations (such as bias adjustment) to 
    each part as needed, ensuring accurate results regardless of 
    the sign of the input number.
*/

/* Computes the value (3/4)x rounded toward zero with no overflow */
int threefourths(int x)
{
  int is_neg = (x & INT_MIN) != 0;

  /* Split number into two parts 30 msb (integer part) and 2 lsb (fractional part because we're dividing by 4 or 2^2) */
  int m30 = x & ~0x3;
  int l2 = x & 0x3;

  /* Divide by 4 first to prevent overflow */
  m30 >>= 2;
  /* Then multiply by 3 */
  m30 = (m30 << 2) - m30;

  /* We have to multiply by 3 first on the fractional part because it's guaranteed to be less than 4 */
  l2 = (l2 << 2) - l2;
  int bias = (1 << 2) - 1;
  /* Add the bias if x is negative to round toward zero */
  (is_neg && (l2 += bias));
  /* Divide by 4 */
  l2 >>= 2;

  return m30 + l2;
}

int main(void)
{
  printf("%d\n", threefourths(10));
  assert(threefourths(8) == 6);
  assert(threefourths(9) == 6);
  assert(threefourths(10) == 7);
  assert(threefourths(11) == 8);
  assert(threefourths(12) == 9);

  assert(threefourths(-8) == -6);
  assert(threefourths(-9) == -6);
  assert(threefourths(-10) == -7);
  assert(threefourths(-11) == -8);
  assert(threefourths(-12) == -9);  
  return 0;
}
