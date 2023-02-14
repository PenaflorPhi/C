/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted(i.e, 1 changed into 0 and vice versa), leaving the other unchanged. */
#include <stdio.h>
#define BITS 32 // sizeof(int) * 8
#define MASK 1

int invert(int x, int p, int n);

int main(int argc, char *argv[]) {
  int x = 11193599;
  int p = 23;
  int n = 8;
  printf("%d\n", invert(x, p, n));
  return 0;
}

/* invert works in n steps:
 * 1. We start by creating two variables, x1 and x2, we initialize them to zero.
 *
 * 2. For the n bits that start at position p we assign x1 the same bit as x and x2 the opposite
 * bit.
 *
 * 3. The expression ```(x & ~x1) | x2``` can be broken into two expressions:
 * 	3.1 total = (x & ~x1) the bits of total to those of x, except for the n bits that start at
 * position p, those are set to zero.
 * 	3.2 (total) | x2 merges the two values, since the n bits of total at position p are zero and
 * the n bits of total at position are the same as x1 but inverted this step gives us our desired
 * result.
 */

int invert(int x, int p, int n) {
  int          x1 = 0;
  int          x2 = 0;
  unsigned int mask;

  for (int i = p; i > p - n; --i) {
    mask = x & (MASK << i);
    x1   |= mask;
    mask = ~x & (MASK << i);
    x2   |= mask;
  }

  int total = (x & ~x1) | x2;

  return total;
}
