/* Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with
 * a conditional expression instead of if-else. */

#include <stdio.h>
#define MAXLINE 1000

int  nuggetchar(char s[]);
void lower(char s[]);

int main(int argc, char *argv[]) {
  char s[MAXLINE];
  while (nuggetchar(s)) {
    lower(s);
    printf("%s", s);
  }

  return 0;
}

int nuggetchar(char s[]) {
  int  i = 0;
  char c;
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') { s[i++] = c; }
  s[i] = '\0';

  return i;
}

void lower(char s[]) {
  for (int i = 0; s[i] != '\0'; ++i) {
    (s[i] > 64 && s[i] < 91) ? (s[i] += 32) : (s[i]);
  }
}
