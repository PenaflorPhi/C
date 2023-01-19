#include <stdio.h>
#define MAXLINE 20 /* Maximum input line size. */

int  nugetline(char line[], int maxline);
void copy(char to[], char from[]);

/* Print longest input line. */
int main() {
  int  len;              /* Current line length. */
  int  max;              /* Maximum length seen so far. */
  char line[MAXLINE];    /* Current input line. */
  char longest[MAXLINE]; /* Longest line saved here. */

  max = 0;
  while ((len = nugetline(line, MAXLINE)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) { /* There was a line*/
    printf("%s", longest);
  }

  return 0;
}

/* nugetline: read a line into s, return length */
/* There is already a getline function in UNIX-Like systems, nugetline is just
 * to avoid clashes. */
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

/* copy: copy 'from' into 'to'; assume to is big enough. */
void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
