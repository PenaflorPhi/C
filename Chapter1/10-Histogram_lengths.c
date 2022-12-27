/* Exercise 1-13. Write a program to print a histogram of the lengths of words
 * in its input. */

#include <stdio.h>
#define IN         1
#define OUT        0
#define MAX_LENGTH 20

int main() {
  int c, state, char_count;
  int word_length[MAX_LENGTH];

  state      = OUT;
  char_count = 0;

  for (int i = 0; i < MAX_LENGTH; ++i) {
    word_length[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;

      ++word_length[char_count];
      char_count = 0;
    } else if (state == OUT) {
      state = IN;
    } else {
      ++char_count;
    }
  }

  for (int i = 0; i < MAX_LENGTH; ++i) {
    printf("%d: %d", i + 1, word_length[i]);
    for (int j = word_length[i]; j > 0; --j) {
      printf("|");
    }
    printf("\n");
  }

  return 0;
}
