/* Write a program to print the corresponding Celsius to Fahrenheit table*/

#include <stdio.h>

int main() {
  float fahr, celsius;
  int   lower, upper, step;

  lower = 0;
  upper = 300;
  step  = 20;

	celsius = lower;

	printf(" °C \t °F\n");
	while(celsius <= upper){
		fahr = (9.0/5.0) * celsius + 32;
		printf("%3.0f\t%5.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

  return 0;
}
