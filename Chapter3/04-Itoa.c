/* Exercise 3-4. In a two's complement number representation, our version of itoa does not handle
 * the largest negative number, that is, the value of n equal to -(2 ** (wordsize - 1)). Explain why
 * not. Modify it to print the value correctly, regardless of the machine on which it runs.*/

#include <limits.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char *argv[]) {
  int  x = INT_MIN;
  char s[MAXLINE];

  itoa(x, s);

  printf("%s\n", s);

  return 0;
}

// The function does not handle the case where n = INT_MIN, this is because |INI_MIN| > |INT_MAX|,
// so when we do n = -n, we overflow. There are multiple solutions to this issue, the one
// implemented here just adds one to n so that it doesn't overflow, and just handles it as and edge
// case.
// * Other solution could be to store n as a long, the function will not overflow with INT_MIN but
// will with LONG_MIN.
void itoa(int n, char s[]) {
  int i = 0, flag = 0;
  int sign;
  if (n == INT_MIN) {
    ++n;
    flag = 1;
  }
  if ((sign = n) < 0) { n = -n; }
  do { s[i++] = n % 10 + '0'; } while ((n /= 10) > 0);

  if (sign < 0) { s[i++] = '-'; }
  if (flag) { s[strlen(s)] += 1; }

  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  for (int i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    int c = s[i];
    s[i]  = s[j];
    s[j]  = c;
  }
}
