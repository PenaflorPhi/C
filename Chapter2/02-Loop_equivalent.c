/* Exercise 2-2. Write a loop equivalent to the for loop above without using &&
 * or ||.
 * The for loop is:
 * for(i = 0; i < lim-1 && (c = getchar) != '\n' && c!= EOF; ++i){
 * 	s[i]= c;
 * }
 * */

#include <stdio.h>
#define MAXLINE 1000

int nugetline(char s[], int max);

int main(int argc, char *argv[]) {
  char string[MAXLINE];
  int  length;

  while ((length = nugetline(string, MAXLINE)) > 0) {
    printf("%s", string);
  }

  return 0;
}

int nugetline(char s[], int max) {
  int  i;
  char c;
  for (i = 0; i < max - 1; ++i) {
    c = getchar();
    if (c == '\n') break;
    if (c == EOF) break;
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
