#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "config.h"

// Function to perform binary search
int binarySearch(int arr[], int item, int low, int high) {
  if (high <= low)
    return (item > arr[low]) ? (low + 1) : low;

  int mid = (low + high) / 2;

  if (item == arr[mid])
    return mid + 1;

  if (item > arr[mid])
    return binarySearch(arr, item, mid + 1, high);
  return binarySearch(arr, item, low, mid - 1);
}

// Function to perform binary insertion sort
void binaryInsertionSort(int arr[], int n) {
  int i, loc, j, selected;

  for (i = 1; i < n; ++i) {
    selected = arr[i];
    loc = binarySearch(arr, selected, 0, i - 1);

    for (j = i - 1; j >= loc; --j)
      arr[j + 1] = arr[j];

    arr[j + 1] = selected;
  }
}

int main() {
  clock_t start, end;
  double cpu_time_used;

  start = clock();

  int arr[QUANTITY];

  FILE *file;

  file = fopen(FILENAME, "r");

  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  for (int i = 0; i < QUANTITY; i++) {
    fscanf(file, "%d", &arr[i]);
  }

  fclose(file);

  printf("sorting array...\n");
  binaryInsertionSort(arr, QUANTITY);
  printf("sorted array\n");

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Execution time: %f\n", cpu_time_used);

  return 0;
}