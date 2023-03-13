/* Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third
 * argument is a minimum filed width; the converted number must be padded with blanks on the left if
 * necessary to make it wide enough. */

#include <limits.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 128

void itoa(int n, int d, char s[]);
void reverse(char s[]);

int main(int argc, char *argv[]) {
  int  x = INT_MIN;
  int  d = 12;
  char s[MAXLINE];

  itoa(x, d, s);

  printf("%s\n", s);
  return 0;
}

void reverse(char s[]) {
  int i, j;
  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    int swap = s[i];
    s[i]     = s[j];
    s[j]     = swap;
  }
}

void itoa(int n, int d, char s[]) {
  int i = 0, flag = 0;
  int sign;
  if (n == INT_MIN) {
    ++n;
    flag = 1;
  }
  if ((sign = n) < 0) { n = -n; }

  do { s[i++] = n % 10 + '0'; } while ((n /= 10) > 0);

  if (flag) { s[strlen(s)] += 1; }
  if (sign < 0) { s[i++] = '-'; }
  while (i < d) { s[i++] = ' '; }

  s[i] = '\0';
  reverse(s);
}
