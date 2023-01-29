/* Exercise 2-3. Write a function htoi(s), which converts a string of
 * hexadecimal digits (including an optional 0x or 0X) into its equivalent
 * integer value. The allowable digits are 0 through 9, a through f, and A
 * through F. */

#include <stdio.h>
#define MAXLINE 1000

int nugetline(char s[], int size);
int string_to_hex(char to[], const char from[]);
int htoi(const char s[], int size);
int power(int base, int exponent);

int main(int argc, char *argv[]) {
  int  size;
  char string[MAXLINE];
  char hex[MAXLINE];

  while (nugetline(string, MAXLINE)) {
    size        = string_to_hex(hex, string);
    int decimal = htoi(hex, size);
    printf("0x%s\tDec: %d\n", hex, decimal);
  }

  return 0;
}

int nugetline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n' && c != '\t' &&
              c != ' ';
       ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}

int htoi(const char s[], int size) {
  int i   = 0;
  int sum = 0;

  for (; i <= size; ++i) {
    int n = 0;
    if (s[i] >= '0' && s[i] <= '9') {
      n = s[i] - '0';
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      n = s[i] - '7'; // 'A' = 65, '7' = 55. 'A' - '7' = 10
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      n = s[i] - 'W'; // 'a' = 97, 'W' = 87. 'a' - 'W' = 10
    }
    sum += n * power(16, size - i - 1);
  }
  return sum;
}

int power(int base, int exponent) {
  int p = 1;
  for (int i = exponent; i > 0; --i) {
    p = p * base;
  }
  return p;
}

int string_to_hex(char to[], const char from[]) {
  int i = 0;
  int j = 0;
  if (from[0] == '0' && from[1] == 'x' || from[1] == 'X') {
    i += 2;
  }
  for (; from[i] != '\0'; ++i) {
    if (from[i] >= 'a' && from[i] <= 'f' || from[i] >= 'A' && from[i] <= 'F' ||
        from[i] >= '0' && from[i] <= '9') {
      to[j] = from[i];
      ++j;
    }
  }
  to[j] = '\0';

  return j;
}
