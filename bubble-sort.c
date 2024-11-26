#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"

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

  int qty = 1000, min_value = -100, max_value = 100;

  int arr[qty];

  srand(time(0));

  for (int i = 0; i < qty; i++) {
    arr[i] = randNumber(min_value, max_value);
  }

  printf("sorting array...\n");
  bubbleSort(arr, qty);
  printf("sorted array\n");

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Execution time: %f\n", cpu_time_used);

  return 0;
}