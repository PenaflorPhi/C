/* Exercise 2-7. Write a function invert(x,p,n) that returns x with the n bits that begin at
 * position p inverted(i.e, 1 changed into 0 and vice versa), leaving the other unchanged. */
#include <stdio.h>
#define MASK 1

int invert(int x, int p, int n);

int main(int argc, char *argv[]) {
  int i = invert(170, 4, 2);
  printf("%d\n", i);
  return 0;
}

int invert(int x, int p, int n) {
  int               total;
  long unsigned int x1 = 0;
  long unsigned int x2 = 0;

  for (int i = p; i > p - n; --i) {
    unsigned int mask = x & (MASK << i);
    x1                |= mask;
  }
  x1 = ~x1;

  for (int i = p; i > p - n; --i) {
    unsigned int mask = x1 & (MASK << i);
    x2                |= mask;
  }

  total = x & x1;
  total = total | x2;

  return total;
}
