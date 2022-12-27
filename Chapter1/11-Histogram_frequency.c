/* Exercise 1-14. Write a program to print a histogram of the frequencies of
 * different characters in its input. */

#include <stdio.h>
#define CHAR_MAX 128

int main() {
  int c;
  int char_frquency[CHAR_MAX];

  for (int i = 0; i < CHAR_MAX; ++i) {
    char_frquency[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    ++char_frquency[c];
  }

  // Prints a histogram for the frequency of each digit.
  // Can be modify to print the frequency of each character in the ANSI standard
  // by modifying the boundaries [0,128].
  for (int i = 48; i < 58; ++i) {
    printf("%c : %d", i, char_frquency[i]);
    for (int j = char_frquency[i]; j > 0; --j) {
      printf("|");
    }
    printf("\n");
  }

  return 0;
}
