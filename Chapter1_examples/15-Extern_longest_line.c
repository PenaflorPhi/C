#include <stdio.h>

#define MAXLINE 1000 /* Maximum input line size. */

int  max;              /* Maximum length seen so far. */
char line[MAXLINE];    /* Current input line. */
char longest[MAXLINE]; /* Longest line saved here. */

int  nugetline(void);
void copy(void);

/* Print longest input line; specialized version */
int main() {
  int len;
	extern int max;
	extern char longest[];
  max;

  max = 0;

  while ((len = nugetline()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  if (max > 0) { /* There was a line. */
    printf("%s", longest);
  }
}

/* nugetline: Specialized version. */
int nugetline(void) {
  int         c, i;
  extern char line[];

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n'){
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* copy: Specialized version. */
void copy(void){
	int i;
	extern char line[], longest[];

	i = 0;
	while((longest[i] = line[i]) != '\0'){
		++i;
	}
}
