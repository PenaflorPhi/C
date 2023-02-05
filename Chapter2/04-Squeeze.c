/* Exercise 2-4. Write an alternate version of squeeze(s1, s2) that deletes each
 * character in s1 that matches any character in the string s2. */

#include <stdio.h>
#define CHARACTER_SET 128
#define MAXLINE       1000

void nuggetline(char s[], int max);
void get_chars(char store[], char const get[]);
void squeeze(char clean_line[], char const second_line[], char const avoid[]);

int main(int argc, char *argv[]) {
  char seen_characters[CHARACTER_SET];
  char first_line[MAXLINE];
  char second_line[MAXLINE];
  char clean_line[MAXLINE];

  // We start by getting the two lines required copied to their respective
  // arrays.
  printf("Input (First line):\n");
  nuggetline(first_line, MAXLINE);
  printf("Input (Second line):\n");
  nuggetline(second_line, MAXLINE);

  // Then we make an array of all the characters that appear in the first line.
  get_chars(seen_characters, first_line);
  // Lastly we copy all the characters in the second line that do not appear in
  // the previous array.
  squeeze(clean_line, second_line, seen_characters);

  printf("%s\n", clean_line);

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

/* The squeeze() function works by copying each character in second_line that is
 * not in the avoid list, we achieve this by simply looking if the numerical
 * value of each character and then checking if the corresponding value in the
 * avoid list is either 0 or 1. */
void squeeze(char clean_line[], char const second_line[], char const avoid[]) {
  int i, j;
  for (i = 0, j = 0; second_line[i] != '\0'; ++i) {
    int k = second_line[i];
    if (avoid[k] == 0) {
      clean_line[j++] = second_line[i];
    }
  }
  clean_line[j] = '\0';
}
