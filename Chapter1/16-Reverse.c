/* Exercise 1-19. Write a function reverse(s) that reverse the character string
 * s. Use it to write a program that reverse its input a line at a time. */

#include <stdio.h>
#define MAXLINE 1000

int  nugetline(char s[], int maxsize);
void reverse(char s[], int length);

int main() {
  char s[MAXLINE];
  int  length;

  while ((length = nugetline(s, MAXLINE)) > 0) {
    reverse(s, length);
  }

  return 0;
}

int nugetline(char s[], int maxsize) {
  char c;
  int  i;
  for (i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c = '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

	return i;
}

void reverse(char s[], int length){
	int i;
	for(i = length - 2; i >= 0; --i){
		putchar(s[i]);
	}
	printf("\n");
}
