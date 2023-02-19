/* Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
 * Explain why. Use this observation to write a faster version of bitcount. */

/* Answer:
 * When we do the operation x &= (x-1) two things happen, first we're subtracting one from the
 * number, that much is obvious, but, when the x is even (the last digit is zero) that subtraction
 * has to be carried over, flipping all the zero to the left until the next bit is encountered, bit
 * which also flips to zero. Then, when we do &= we're setting the bits to be only those after last
 * least significant bit.
 * This can be visualized in the next table: */

// x         : 0110 0101 // x = 100
// (x - 1)   : 0110 0100
// ---------------------
// x &= (x-1): 0110 0100 // x = 100
// (x-1)     : 0110 0011
// ----------------------
// x &= (x-1): 0110 0000
// (x-1)     : 0101 1111
// ----------------------
// x &= (x-1): 0100 0000

#include <stdio.h>

int bitcount(int x);

int main(int argc, char *argv[]) {
  int x = -55;

  printf("%d, %d\n", x, bitcount(x));

  return 0;
}

int bitcount(int x) {
  int b = 0;
  while (x != 0) {
    printf("%d, %d\n", x, b);
    x &= (x - 1);
    ++b;
  }
  printf("%d, %d\n", x, b);

  return b;
}
