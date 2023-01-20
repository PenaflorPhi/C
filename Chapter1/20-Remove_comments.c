/* Exercise 1-23. Write a program to remove all comment from a C program. Don't
 * forget to handle quoted strings and character constant properly. C comments
 * do not nest. */

#include <stdio.h>
#define MAXLINE 1000
#define IN      1
#define OUT     0

int  nugetline(char s[], int lim);
void remove_comments(char to[], char from[]);
int  in_comment = OUT;
int  in_quotes  = OUT;

int main() {
  int  length;
  char line[MAXLINE];
  char no_comment_string[MAXLINE];

  // The nugetline implementation is taken straight from the examples, perhaps
  // the function should be modified to be a void instead of an int, that way we
  // reduce one variable that's not really needed (length).
  while ((length = nugetline(line, MAXLINE)) > 0) {
    remove_comments(no_comment_string, line);
    printf("%s", no_comment_string);
  }
  printf("/* Test */");
  return 0;
}

int nugetline(char s[], int lim) {
  int  i = 0;
  char c;

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

/*Another comment, we test this program by using the same source. */

/* The remove_comments function works by checking two characters at the same
 * time, if the two characters are the escape sequence for the start of the end
 * a comment it updates the in_comment variable, the in_comment is external
 * since the state must be preserved between lines. */

void remove_comments(char to[], char from[]) {
  extern int in_comment;
  extern int in_quotes;

  int j = 0;

  for (int i = 0; from[i] != '\0'; ++i) {
    if (!in_quotes) {
      if (from[i] == '/' && from[i + 1] == '*') {
        in_comment = IN;
      } else if (from[i] == '*' && from[i + 1] == '/') {
        in_comment = OUT;
        ++i; // This is needed, otherwise we add the '/' to they to[] array.
      } else if (!in_comment) {
        to[j] = from[i];
        ++j;
      }
      if (from[i] ==
          '"') { // We just check if we're now in a quote, we check after the
                 // fact since we also need to get the first '"'.
        in_quotes = IN;
      }
    } else {
      to[j] = from[i];
      ++j;
      if (from[i] == '"') {
        in_quotes = OUT;
      }
    }
  }
  to[j] = '\0';
}
