/* Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the same
 * tab stops as for detab, When either a tab or a single blank would suffice to
 * reach a tab stop, which should be given preference? */

#include <stdio.h>
#define MAXLINE 1000
#define TABSTOP 2

int  nugetline(char s[], int maxlength);
void entab(char to[], char from[]);

int  main() {
  char line[MAXLINE];
  char tabbed[MAXLINE * TABSTOP];

  while (nugetline(line, MAXLINE) > 0) {
    entab(tabbed, line);
    printf("%s", tabbed);
  }

  return 0;
}

int nugetline(char s[], int maxlength) {
  int  i;
  char c;

  for (i = 0; i < maxlength - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i;
}

/* The entab function works by copying the array into a second array and
 * counting the number of consecutive spaces, if the number of consecutive
 * spaces is equal to TABSTOP it copies a single tab into the second array,
 * otherwise it copies the array verbatim. */
void entab(char tabbed[], char line[]) {
  int i, j, spaces, tabs;
  i = j  = 0;
  spaces = tabs = 0;

  while (line[i] != '\0') {
    if (line[i] == ' ') {
      ++spaces;
      if (spaces == TABSTOP) {
        ++tabs;
        spaces = 0;
      }
    } else {
      // We copy the spaces and tabs in to the second array, we count backwards,
      // this way the number tabs and spaces stored goes to zero.
      for (tabs; tabs > 0; --tabs, ++j) {
        tabbed[j] = '\t';
      }
      for (spaces; spaces > 0; --spaces, ++j) {
        tabbed[j] = ' ';
      }
      //
      // clang and cppcheck say the previous for loops should be written as:
      // for(; tabs > 0; --tabs, ++j)
      // for(; spaces > 0; --tabs, ++j)
      // and give the following warning: Expression result unused. I'm not
      // really sure what the warning means but I would rather not change it,
      // it's clearer for me what we're doing if I don't omit the variable.

      tabbed[j] = line[i];
      ++j;
    }
    ++i;
  }
}
