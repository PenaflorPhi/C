/* Exercise 1-12. Write a program that print its input one word per line. */

#include <stdio.h>
#define IN  1
#define OUT 0

int main() {
  int c, state;
  state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (state == OUT) {
        c = '\0'; // If not the first blank characters then this removes the
                  // character and replaces it by nothing.
      } else {
        c = '\n';
      }
      state = OUT;
    } else if (state == OUT) {
      state = IN;
    }
    putchar(c);
  }
  return 0;
}
