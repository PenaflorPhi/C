/* Exercise 3-3. Write a function expand(s1, s2) that expands shorthand notation like a-z in the
 * string s1 into the equivalent complete list abc...xyz in s2. Allow for letter of either case and
 * digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
 * trailing - is taken literally.*/

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int  nuggetline(char s[]);
void expand(const char s1[], char s2[]);

int main(int argc, char *argv[]) {
  char s1[MAXLINE], s2[MAXLINE];
  while (nuggetline(s1)) {
    expand(s1, s2);
    printf("%s", s2);
  }

  return 0;
}

// Nuggetfunction: Just save a newline.
int nuggetline(char s[]) {
  int  i;
  char c;
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF; ++i) {
    s[i] = c;
    if (c == '\n') { break; }
  }
  s[++i] = '\0';

  return i;
}

// To expand a string like a-z we start by getting the numerical values of a and z, as a starting
// and ending point, then we iterate over those values and add them to the string s2.
// We use '-' as a marker that we should iterated, we just check the previous and next character in
// the strings to get our starting and ending points; after adding all the characters to we add one
// to i, that we don't add twice the last character.
void expand(const char s1[], char s2[]) {
  int i, j;
  for (i = 0, j = 0; i < MAXLINE - 1 && j < MAXLINE - 1 && s1[i] != '\0'; ++i, ++j) {
    if (s1[i] == '-') {
      int start     = s1[i - 1];
      int end       = s1[i + 1];
      int direction = (start < end) ? 1 : -1;

      for (int k = start + direction; j < MAXLINE - 1; k += direction, ++j) {
        s2[j] = k;
        if (k == end) { break; }
      }
      ++i;
    } else {
      s2[j] = s1[i];
    }
  }
  s2[j] = '\0';
}
