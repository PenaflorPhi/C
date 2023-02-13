/* Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to
 * the right by n bit positions. */
#include <stdio.h>
#define BITS 32
#define MASK 1

int rightrot(int x, int n);

int main(int argc, char *argv[]) {
  int x = 1090453674;
  printf("%d\n", x);
	x = rightrot(x, 1);
  printf("%d\n", x);


  return 0;
}

int rightrot(int x, int n) {
  unsigned int       x1    = 0;
  unsigned int       x2    = 0;
  unsigned short int shift = n % 32;

  for (int i = 0; i < shift; ++i) {
    unsigned long int mask = x & (MASK << i);
    x1                     |= mask;
  }
	x1 = x1 << (BITS - shift);
  for (int i = shift; i < BITS - 1; ++i) {
    unsigned long int mask = x & (MASK << i);
    x2                     |= mask;
  }
	x2 = x2 >> shift;

  return x1 | x2;
}
