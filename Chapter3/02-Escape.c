/* Exercise 3-2. Write a function escape(s,t) that converts characters like newline and tab into
 * visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
 * function for the other direction as well, converting escape sequences into the real characters.
 */

#include <stdio.h>
#define MAXLINE 1000

int  nugetchar(char s[]);
void escape(char s[], const char t[]);
void reverse_escape(char s[], const char t[]);

int main(int argc, char *argv[]) {
  char s[MAXLINE];
  char t[MAXLINE];

  while (nugetchar(s)) {
    escape(t, s);
    printf("%s\n", t);
    reverse_escape(t, s);
    printf("%s", t);
  }
  return 0;
}

int nugetchar(char s[]) {
  int  i;
  char c;
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF; ++i) {
    s[i] = c;
    if (c == '\n') {
      s[++i] = '\0';
      break;
    }
  }
  return i;
}

void escape(char s[], const char t[]) {
  int i, j;
  for (i = 0, j = 0; j < MAXLINE - 1; ++i, ++j) {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j]   = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j]   = 't';
      break;
    default:
      s[j] = t[i];
      break;
    }
  }

  s[j] = '\0';
}

void reverse_escape(char s[], const char t[]) {
  int i, j;
  for (i = 0, j = 0; j < MAXLINE - 1; ++i, ++j) {
    switch (t[i]) {
    case '\\':
      switch (t[++i]) {
      case '\\':
        s[j++] = '\\';
        s[j] = '\\';
        break;
      case 't':
        s[j] = '\t';
        break;
      case 'n':
        s[j] = '\n';
        break;
      }
      break;

    default:
      s[j] = t[i];
      break;
    }
  }
}
