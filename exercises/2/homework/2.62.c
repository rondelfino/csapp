#include <stdio.h>
#include <limits.h>

/* Returns 1 if machine uses arithmetic right shifts for ints and 0 if it
 * doesn't */
int int_shifts_are_arithmetic() 
{
 int num = -1;
 int w = sizeof(int) << 3;
 return ((num >> 1) >> (w - 1)) & 1;
}

int main(void) 
{ 
 printf("%d\n", int_shifts_are_arithmetic());
 return 0; 
}
