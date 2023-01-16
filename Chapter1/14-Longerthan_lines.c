/* Exercise 1-17. Write a program to print all input lines that are longer than
 * 80 characters. */
#include <stdio.h>
#define MAXLINE 1000
#define MINLINE 80

int nugetline(char s[], int maxline);

int main() {
  int  len;
  char line[MAXLINE];

  while ((len = nugetline(line, MAXLINE)) > 0) {
    if (len > MINLINE) {
      printf("%s", line);
    }
  }

  return 0;
}

int nugetline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
