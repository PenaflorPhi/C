/* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
 * use a function for conversion. */
#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP  20

float fahr_to_cels(int n);

int main() {
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr += STEP) {
    printf("%3d\t%6.2f\n", fahr, fahr_to_cels(fahr));
  }

  return 0;
}

float fahr_to_cels(int fahrenheit) {
  float cels = (5.0 / 9.0) * (fahrenheit - 32);
  return cels;
}
