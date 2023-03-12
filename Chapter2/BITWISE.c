#include <math.h>
#include <stdio.h>
#define BITS 16

void toBinary(int n, int array[]);
int  toDecimal(int const array[]);
void initArray(int array[]);
void printArray(int array[]);

void bitwiseNOT(int const firstArray[], int secondArray[]);
void bitwiseAND(int const firstArray[], int const secondArray[], int thirdArray[]);
void bitwiseOR(int const firstArray[], int const secondArray[], int thirdArray[]);
void bitwiseXOR(int const firstArray[], int const secondArray[], int thirdArray[]);
void bitwiseLeft(int const firstArray[], int secondArray[], int n);
void bitwiseRight(int const firstArray[], int secondArray[], int n);

int main(int argc, char *argv[]) {
  int x, y, z;
  int firstArray[BITS];
  int secondArray[BITS];
  int thirdArray[BITS];

  initArray(firstArray);
  initArray(secondArray);
  initArray(thirdArray);

  scanf("%d", &x);
  scanf("%d", &y);

  toBinary(x, firstArray);
  toBinary(y, secondArray);

  printf("%d: ", x);
  printArray(firstArray);
  printf("%d: ", y);
  printArray(secondArray);

  // bitwiseAND(firstArray, secondArray, thirdArray);
  // z = toDecimal(thirdArray);
  // printf("AND: \n%d: ", z);
  // printArray(thirdArray);

  // bitwiseOR(firstArray, secondArray, thirdArray);
  // z = toDecimal(thirdArray);
  // printf("%d: ", z);
  // printArray(thirdArray);

  // bitwiseXOR(firstArray, secondArray, thirdArray);
  // z = toDecimal(thirdArray);
  // printf("%d: ", z);
  // printArray(thirdArray);

  // bitwiseNOT(firstArray, thirdArray);
  // z = toDecimal(thirdArray);
  // printf("%d: ", z);
  // printArray(thirdArray);

  // int n;
  // scanf("%d", &n);
  // bitwiseLeft(firstArray, thirdArray, n);
  // printf("BITWISE LEFT\n");
  // printArray(firstArray);
  // printArray(thirdArray);
  //
  // bitwiseRight(firstArray, thirdArray, n);
  // printf("BITWISE RIGHT\n");
  // printArray(firstArray);
  // printArray(thirdArray);
  return 0;
}

void toBinary(int n, int array[]) {
  for (int i = 0; i < BITS; ++i) {
    array[BITS - i - 1] = n % 2;
    n                   /= 2;
  }
}

int toDecimal(int const array[]) {
  int n = 0;
  for (int i = 0; i < BITS; ++i) {
    n += array[BITS - i - 1] * pow(2, i);
  }
	if(array[0] == 1){
		n += 2147483648;
	}
  return n;
}

void initArray(int array[]) {
  for (int i = 0; i < BITS; ++i) {
    array[i] = 0;
  }
}

void printArray(int array[]) {
  for (int i = 0; i < BITS; ++i) {
    printf("%d", array[i]);
		if((i + 1) % 4 == 0){
			printf(" ");
		}
  }
  printf("\n");
}

void bitwiseNOT(int const firstArray[], int secondArray[]) {
  for (int i = 0; i < BITS; ++i) {
    if (firstArray[i] == 1) {
      secondArray[i] = 0;
    } else {
      secondArray[i] = 1;
    }
  }
}

void bitwiseAND(int const firstArray[], int const secondArray[], int thirdArray[]) {
  for (int i = 0; i < BITS; ++i) {
    if (firstArray[i] != secondArray[i]) {
      thirdArray[i] = 0;
    } else {
      thirdArray[i] = firstArray[i];
    }
  }
}

void bitwiseOR(int const firstArray[], int const secondArray[], int thirdArray[]) {
  for (int i = 0; i < BITS; ++i) {
    if ((firstArray[i] == 1) || (secondArray[i] == 1)) {
      thirdArray[i] = 1;
    } else {
      thirdArray[i] = 0;
    }
  }
}

void bitwiseXOR(int const firstArray[], int const secondArray[], int thirdArray[]) {
  for (int i = 0; i < BITS; ++i) {
    if (firstArray[i] == secondArray[i]) {
      thirdArray[i] = 0;
    } else {
      thirdArray[i] = 1;
    }
  }
}

void bitwiseLeft(int const firstArray[], int secondArray[], int n) {
  initArray(secondArray);
  for (int i = 0; (i + n) < BITS; ++i) {
    secondArray[i] = firstArray[i + n];
  }
}

void bitwiseRight(int const firstArray[], int secondArray[], int n) {
  initArray(secondArray);
  for (int i = 0; (i + n) < BITS; ++i) {
    secondArray[i + n] = firstArray[i];
  }
}
