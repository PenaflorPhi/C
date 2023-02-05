/* Exercise 2-5. Write the function any(s1, s2), which returns the first
 * location in the string s1 where any character from the string s2 occurs, or .
 * -1 if s1 contains no characters from s2. (The standard library function
 * strpbrk does the same job but returns a pointer to the location. )*/

#include <stdio.h>
#define CHARACTER_SET 128
#define MAXLINE       1000
#define SUCCESS       1
#define FAIL          -1

void nuggetline(char s[], int max);
void get_chars(char store[], char const get[]);
int  any(char const second_line[], char const avoid[]);

int main(int argc, char *argv[]) {
  char seen_characters[CHARACTER_SET];
  char first_line[MAXLINE];
  char second_line[MAXLINE];

  // We start by getting the two lines required copied to their respective
  // arrays.
  printf("Input (First line):\n");
  nuggetline(first_line, MAXLINE);
  printf("Input (Second line):\n");
  nuggetline(second_line, MAXLINE);

  // Then we make an array of all the characters that appear in the first line.
  get_chars(seen_characters, first_line);
  int x = any(second_line, seen_characters);

  // This is just a visual indicator of where is the first character that both
  // lines share.
  for (int i = 0; i < x; ++i) {
    printf(" ");
  }
  printf("^");

  // This is the numerical place where it occurs in the second line.
  printf("%d\n", x);
  return 0;
}

// The usual getline function.
void nuggetline(char s[], int max) {
  int  i;
  char c;
  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
}

/* We make an array of zeros and ones, we indicate that a character appears in
 * the first input line by getting its numerical value and changing the n-th
 * position in our array from 0 to 1. */
void get_chars(char store[], const char get[]) {
  int i;
  for (i = 0; i < CHARACTER_SET; ++i) {
    store[i] = 0;
  }

  for (i = 0; get[i] != '\0'; ++i) {
    int n    = get[i];
    store[n] = 1;
  }
}

// We proceed in a similar way to the previous exercise, we check one by one if
// the characters are in the avoid list, if they are it triggers a return and we
// return the counter at that position.
int any(char const second_line[], char const avoid[]) {
  int i = 0;
  while (second_line[i] != '\0' && second_line[i] != '\n') {
    int n = second_line[i++];
    if (avoid[n] != 0) {
      return i;
    }
  }
  return FAIL;
}
