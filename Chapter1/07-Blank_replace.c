/* Exercise 1-9. Write a program to copy its input to its output, replacing each
 * sting of one or more blanks by a single blank. */

#include <stdio.h>

int main() {
  int c, flag;
  flag = 0;

  while ((c = getchar()) != EOF) {
    if (flag == 0) {
      putchar(c);
    }
    if (c == ' ') {
      flag = 1;
    } else {
      flag = 0;
    }
  }

  return 0;
}
