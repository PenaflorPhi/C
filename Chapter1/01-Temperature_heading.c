/* Modify the temperature conversion program to print a heading above the table.
 */

#include <stdio.h>

int main() {
  float fahr, celsius;
  int   lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;

  fahr = lower;

  printf(" °F \t °C\n");
  while (fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%3.0f\t%5.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
