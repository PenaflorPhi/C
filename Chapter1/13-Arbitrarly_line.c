/* Exercise 1-16. Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrarily long input lines, and as much as
 * possible of the text. */

#include <stdint.h>
#include <stdio.h>
#define MAXLINE 1000

int  nugetline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int64_t len, max;
  char    line[MAXLINE];
  char    longest[MAXLINE];

  max = 0;

  while ((len = nugetline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }

  if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

int nugetline(char s[], int lim) {
  int64_t c, i;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 1) {
      s[i] = c;
    }
  }

  if (c == '\n' && i < lim - 1) {
    s[i] = c;
    ++i;
  }
  if (i < lim - 1) {
    s[i] = '\0';
  } else {
    s[lim] = '\0';
  }
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough. */
void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
