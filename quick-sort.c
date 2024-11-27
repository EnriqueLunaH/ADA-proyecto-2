#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "config.h"

// Function to swap two elements
void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
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
  quickSort(arr, 0, QUANTITY - 1);
  printf("sorted array\n");

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Execution time: %f\n", cpu_time_used);

  return 0;
}