/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to
 * the right by n bit positions. */
#include <stdio.h>
#define BITS 32
#define MASK 1

int rightrot(int x, int n);

int main(int argc, char *argv[]) {
  int x = 11193599;
  int n = 8;
  printf("%d\n", rightrot(x, n));

  return 0;
}

/*rightrot works in four steps:
 * 1. We start by creating three variables, x1,x2 and shift: we initialize x1 and x2 to zero and set
 * shift to be n % 32, this way we don't get any errors if we rotate over once or more.
 *
 * 2. Then we copy the first ```shift``` bits of x to x1.
 *
 * 3. We copy the remaining bits of x to x2.
 *
 * 4. Lastly we shift x1 to the right by ```BITS-shift``` and x2 to the left by ```shift```, this
 * put the bits of x1 and x2 in non-overlapping positions so we just have to use OR on them.
 */

int rightrot(int x, int n) {
  int           x1    = 0;
  int           x2    = 0;
  unsigned char shift = n % 32;

  unsigned int mask;
  for (int i = 0; i < shift; ++i) {
    mask = x & (MASK << i);
    x1   |= mask;
  }

  for (int i = shift; i < BITS - 1; ++i) {
    mask = x & (MASK << i);
    x2   |= mask;
  }

  x1 = x1 << (BITS - shift);
  x2 = x2 >> shift;

  return x1 | x2;
}
