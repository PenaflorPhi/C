/* Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * error like unbalanced parentheses, brackets and braces. Don't forget about
 * quotes, both single and double escape sequences and comments. */

#include <stdio.h>
#define MAXLINE 1000

int  nugetline(char s[], int len);
void balance_check(char s[]);
void balance_error();

/* We check for left and right parentheses, and for the number of single quotes,
 * the same idea can be extrapolated to check for braces, brackets and double
 * quotes or comments. */
int left_parenthesis  = 0;
int right_parenthesis = 0;
int single_quotes     = 0;

int main() {
  int  length;
  char line[MAXLINE];

  while ((length = nugetline(line, MAXLINE)) > 0) {
    balance_check(line);
  }
  balance_error();

  return 0;
}

int nugetline(char line[], int len) {
  int  i;
  char c;

  for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';

  return i;
}

/* balance_check just checks if the char is one of the ones we're checking, if
 * it is, it just updates the count to be used in the balance_error function.
 * Perhaps this should be done after using a function to ignore comments, like
 * the one in the previous exercise. */
void balance_check(char s[]) {
  extern int left_parenthesis;
  extern int right_parenthesis;
  extern int single_quotes;

  for (int i = 0; s[i] != '\0'; ++i) {
    if (s[i] == '(') {
      ++left_parenthesis;
    }
    if (s[i] == ')') {
      ++right_parenthesis;
    }
    if (s[i] == '\'') {
      ++single_quotes;
    }
  }
}

/*This function literally just checks if the number of right and left
 * parentheses is the same, if it's not it's prints out an error. To check if
 * the number of single quotes is balanced we just take the modulo to determine
 * whether the number is even or odd, if it's odd we print an error.*/

/* Perhaps this should take into account comments, using the function from the
 * previous exercise to ignore the count when we're in a comment. */

void balance_error() {
  extern int left_parenthesis;
  extern int right_parenthesis;
  extern int single_quotes;

  if (left_parenthesis != right_parenthesis) {
    printf("The number of parentheses is not balanced:\n");
    printf("There are %d '('\n", left_parenthesis);
    printf("There are %d ')'\n", right_parenthesis);
    printf("The number should be equal.\n");
  }
  if ((single_quotes % 2) != 0) {
    printf("The number of single quotes is not balanced:\n");
    printf("There are %d single quotes.\n", single_quotes);
    printf("The number should be even.\n");
  }
}
