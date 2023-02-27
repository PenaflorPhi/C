#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3000000

int  binsearch(int x, const int v[]);
int  trivialsearch(int x, const int array[]);
void randomPopulate(int array[]);
void printarray(const int array[]);

// Sorting
void swap(int* a, int* b);
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main(int argc, char *argv[]) {
  srand(time(NULL));
  long int x, n1, n2;
  x = rand() % SIZE;
  printf("x: %ld\n", x);
  int    array[SIZE];
  time_t begin, end;

  randomPopulate(array);
	quicksort(array, 0, SIZE - 1);

  printf("DONE!\n");
  begin = time(NULL);
	printf("%ld\n", begin);
  n1    = trivialsearch(x, array);
  end   = time(NULL);
  printf("Time: %ld , Position: %ld \n", begin - end, n1);

  begin = time(NULL);
  n2    = binsearch(x, array);
  end   = time(NULL);
  printf("Time: %ld, Position: %ld\n", begin - end, n2);
	printf("%ld\n", end);

  return 0;
}

/*randomPopulate*/
void randomPopulate(int array[]) {
  for (long int i = 0; i < SIZE; ++i) {
    array[i] = rand() % SIZE;
  }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

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

/*binsearch: find x in v[] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, const int v[]) {
  long int low, high, mid;

  low  = 0;
  high = SIZE - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid]) {
      high = mid - 1;
    } else if (x > v[mid]) {
      low = mid + 1;
    } else {
      return mid;
    }
  }

  return -1;
}

void printarray(const int array[]){
	for(long int i = 0; i < SIZE; ++i){
		printf("%d ", array[i]);
	}
	printf("\b\n");
}
