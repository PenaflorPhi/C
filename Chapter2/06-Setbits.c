/* Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
 * bits that begin at position of p set to rightmost n bits of y, leaving the
 * other bits unchanged.*/

#include <stdio.h>
#define BITS 32 // sizeof(int) * 8
#define MASK 1

int setbits(int x, int p, int y, int n);

int main(int argc, char *argv[]) {
  int x = 129;
  int y = 206;
  int p = 2;
  int n = 3;

  int k = setbits(x, p, y, n);
  printf("%d\n", k);
  return 0;
}

int setbits(int x, int p, int y, int n) {
  // We need to make both place holders long unsigned ints, otherwise there are
  // overflow and sign errors.
  long unsigned int y_place_holder = 0;
  long unsigned int x_place_holder = 0;

  // This part assigns to y_place_holder the n rightmost digits of y and shift
  // them to the position p. If we get the first eight bits and move them to the
  // sixth place of y we can visualize this as:
  // y : 0000 0000 0000 1111 1111 1011 0010 1010
  // y2: 0000 0000 0000 0000 0000 0000 0010 1010
  // -------------------------------------------
  // y3: 0000 0101 0101 0000 0000 0000 0000 0000
  for (int i = 0; i < n; ++i) {
    unsigned int mask = y & (MASK << i);
    y_place_holder    |= mask;
  }
  y_place_holder = y_place_holder << (p - n + 1);
  printf("y: %lu\n", y_place_holder);

  // Now, this part assigns to x_place_holder copies the n bits of x starting at
  // p(I'm counting from the right), making all other bits zero, we then use the
  // NOT operator to invert all bits and we use AND to effectively assign x to
  // x_place_holder, except for the n bits starting at position p, those will be
  // zero.
  for (int i = p; i > p - n; --i) {
    unsigned int mask = x & (MASK << i);
    x_place_holder    |= mask;
  }
  x_place_holder = x & ~(x_place_holder);

  // Finally we return the total value, which is assigned x_place_holder |
  // y_place_holder, this will work since the bits of both numbers have been
  // shifted in such a way that this is logically equivalent to a conventional
  // sum.
  int total_value = x_place_holder | y_place_holder;

  return total_value;
}
