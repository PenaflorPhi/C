#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000

// Arrays
int  trivialsearch(int x, const int array[]);
void randomArray(int array[]);
void printarray(const int array[]);

// Binary Search
int binarySearch(int x, const int array[]);

// Sorting
void swap(int *a, int *b);
void quicksort(int arr[], int low, int high);
int  partition(int arr[], int low, int high);

int main(int argc, char *argv[]) {
  srand(time(NULL));
  long int x, n1, n2;
  x = rand() % SIZE;
  printf("x: %ld\n", x);
  int array[SIZE];

  randomArray(array);
  quicksort(array, 0, SIZE - 1);

  n1 = trivialsearch(x, array);
  printf("Position: %ld \n", n1);

  n2 = binarySearch(x, array);
  printf("Position: %ld\n", n2);

  return 0;
}

void randomArray(int array[]) {
  for (long int i = 0; i < SIZE; ++i) {
    array[i] = rand() % SIZE;
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a       = *b;
  *b       = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i     = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quicksort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

/*Trivialsearch*/
int trivialsearch(int x, const int array[]) {
  for (long int i = 0; i < SIZE; ++i) {
    if (array[i] == x) { return i; }
  }
  return -1;
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

void printarray(const int array[]) {
  for (long int i = 0; i < SIZE; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
