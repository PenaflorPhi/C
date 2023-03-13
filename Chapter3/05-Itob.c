/* Exercise 3-5. Write the function itob(n,s,b) that converts the integer n into
 * a base b character representation in the string s. In particular,
 * itob(n,s,16) formats n as a hexadecimal integer in s. */

#include <limits.h>
#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(int argc, char *argv[]) {
  int  n = INT_MAX;
  int  b = 16;
  char s[MAXLINE];

  for (int i = 0; i < MAXLINE; ++i) { s[i] = 0; }

  itob(n, s, b);
  printf("%s\n", s);

  return 0;
}

// The conversion is fairly straightforward. We use the same algorithm as in the previous program,
// we just replace the 10 with the base, the only extra thing we do is save the result of the
// operation n % b, to check against to possible cases:
// the first is when the module is less than 10, in that case we proceed as in the previous program.
// Other wise we subtract 10 and instead of adding '0' we add 'A' to get the correct values.

void itob(int n, char s[], int b) {
  int i = 0;
  int sign, flag = 0;

  if (b < 0) {
    strcat(s, "Error: Base must be a positive integer");
    return;
  }

  if (n == INT_MIN) {
    ++n;
    flag = 1;
  }

  if ((sign = n) < 0) { n = -n; }

  do {
    int modulo = n % b;
    if (modulo < 10) {
      s[i++] = modulo + '0';
    } else {
      s[i++] = (modulo - 10) + 'A';
    }
  } while ((n /= b) > 0);

  if (sign < 0) { s[i++] = '-'; }
  if (flag) { s[strlen(s)] += 1; }

  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int i, j;
  for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
    int swap = s[i];
    s[i]     = s[j];
    s[j]     = swap;
  }
}
