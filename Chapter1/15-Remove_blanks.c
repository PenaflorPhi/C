/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirely blank lines. */

#include <stdio.h>
#define MAXLINE 1000

int  nugetline(char s[], int maxline);
void cleanline(char s[], int len);

int main() {
  char line[MAXLINE];
  int  length;

  while ((length = nugetline(line, MAXLINE)) > 0) {
    cleanline(line, length);
    printf("%s", line);
  }

  return 0;
}

int nugetline(char s[], int lim) {
  int  i;
  char c;
  for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

void cleanline(char s[], int len) {
  if (len > 1) {
    char c;
    int  i;
    for (i = len - 2; (c = s[i]) == ' ' || c == '\t'; --i) {
      s[i] = '\0';
    }
    s[i] = '\n';
		s[++i] = '\0';
  }
}
