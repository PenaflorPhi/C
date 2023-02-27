#include <stdio.h>
#define SIZE 10
int binarySearch(int x, const int array[]);

int main(int argc, char *argv[]) {
  int x = 4;
  int n = 10;

  int array[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  printf("%d\n", binarySearch(x, array));

  return 0;
}

int binarySearch(int x, const int array[]) {
  int low, high, mid;
  low  = 0;
  high = SIZE - 1;
  mid  = (low + high) / 2;

  while (low <= high && x != array[mid]) {
    if (x > array[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
    mid = (low + high) / 2;
  }

  if (x == array[mid]) {
    return mid;
  } else {
    return -1;
  }
}
