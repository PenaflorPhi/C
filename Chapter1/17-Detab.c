/* Exercise 1-20. Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter? */

#include <stdio.h>
#define TABSTOP 4
#define MAXLINE 1000

int  nugetline(char s[], int maxlength);
void detab(char to[], char from[]);

int  main() {
  char line[MAXLINE];
  char detabbed[MAXLINE * TABSTOP];

  while (nugetline(line, MAXLINE) > 0) {
    detab(detabbed, line);
    printf("%s", detabbed);
  }

  return 0;
}

int nugetline(char s[], int maxlength) {
  int  i;
  char c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

/*The detab function works by simply replacing each tab by the corresponding
 * number of spaces. To obtain the correct number of spaces we calculate the
 * value TABSTOP - (position % TABSTOP), this gives us a number in the range [1,
 * TABSTOP], the corresponding value is the amount of spaces required. */

void detab(char detabbed[], char tabbed[]) {
  int i, j, k;
  i = j = 0;
  while ((detabbed[j] = tabbed[i]) != '\0') {
    if (detabbed[j] == '\t') {
      for (k = TABSTOP - (j % TABSTOP); k > 0; --k, ++j) {
        detabbed[j] = ' ';
      }
    } else {
      ++j;
    }
    ++i;
  }
}
