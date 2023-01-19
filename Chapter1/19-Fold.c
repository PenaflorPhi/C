/* Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

#include <stdio.h>
#define MAXLINE 1000
#define WIDTH   20

int  nugetline(char s[], int max);
void fold(char s[], int length);

int  main() {
  int  length;
  char line[MAXLINE];

  while ((length = nugetline(line, MAXLINE)) > 0) {
    if (length > WIDTH) {
      fold(line, length);
    }
    printf("%s", line);
  }

  return 0;
}

int nugetline(char s[], int max) {
  int  i;
  char c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
}

/* The fold function works by checking the current position and the length of
 * each word, if the sum of the length and the position is greater than WIDTH it
 * changes the last space before the word to a new line. */
/* TODO: Make it work with  hyphenation. */

void fold(char s[], int length) {
  int current_position = 0;
  int word_length;

  for (int i = 0; s[i] != '\0'; ++i, ++current_position) {
    if (s[i] == ' ' || s[i] == '\t') {
      word_length = 0;
      for (int j = i + 1;
           s[j] != ' ' && s[j] != '\t' && s[j] != '\n' && s[j] != '\0'; ++j) {
        ++word_length;
      }
      if (word_length + current_position >= WIDTH) {
        s[i]             = '\n';
        current_position = 0;
      }
    }
  }
}
