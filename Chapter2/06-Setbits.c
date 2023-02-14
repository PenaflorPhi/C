/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n bits that begin at
 * position of p set to rightmost n bits of y, leaving the other bits unchanged.*/

#include <stdio.h>
#define BITS 32 // sizeof(int) * 8
#define MASK 1

int setbits(int x, int p, int y, int n);

int main(int argc, char *argv[]) {
  int x = 11193599;
  int y = -1427050411;
  int p = 15;
  int n = 8;

  int k = setbits(x, p, y, n);
  printf("%d\n", k);
  return 0;
}

/* setbits works by performing five simple actions:
 * 1. We create two variables, x1 and y1, they're both initialized to zero.
 *
 * 2. We copy bit by bit x to x1, starting from the right omitting the n bits starting
 * at position p. This leaves us with a copy of x where the n digits starting at p are zero.
 *
 * 3. We copy bit by bit the first n bits of y to y1.
 *
 * 4. We shift y1 by (p-n+1), this is the position, counting from zero that will align
 * x1 and y1 so that the first n bits of y are in position p.
 *
 * 5. We create a variable total that uses OR to merge both numbers, this is equivalent to
 * using a regular sum.
 */
int setbits(int x, int p, int y, int n) {
  int x1 = 0;
  int y1 = 0;

  unsigned int mask;
  for (int i = BITS - 1; i >= 0; --i) {
    if (i == p) { i = p - n; }
    mask = x & (MASK << i);
    x1   |= mask;
  }

  for (int i = n; i >= 0; --i) {
    mask = y & (MASK << i);
    y1   |= mask;
  }
  y1 <<= (p - n + 1);

  int total = x1 | y1; // This can be omitted by simply returning x1 | y1.

  return total;
}
