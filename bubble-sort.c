#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"
#include "config.h"

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
}

int main() {
  clock_t start, end;
  double cpu_time_used;

  start = clock();

  int arr[QUANTITY];

  srand(time(0));

  for (int i = 0; i < QUANTITY; i++) {
    arr[i] = randNumber(MIN_VALUE, MAX_VALUE);
  }

  printf("sorting array...\n");
  bubbleSort(arr, QUANTITY);
  printf("sorted array\n");

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Execution time: %f\n", cpu_time_used);

  return 0;
}