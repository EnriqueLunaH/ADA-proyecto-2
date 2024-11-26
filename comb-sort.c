#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"

// Function to find the next gap
int getNextGap(int gap) {
  gap = (gap * 10) / 13;
  if (gap < 1)
    return 1;
  return gap;
}

// Function to perform comb sort
void combSort(int arr[], int n) {
  int gap = n;
  int swapped = 1;

  while (gap != 1 || swapped == 1) {
    gap = getNextGap(gap);
    swapped = 0;

    for (int i = 0; i < n - gap; i++) {
      if (arr[i] > arr[i + gap]) {
        int temp = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = temp;
        swapped = 1;
      }
    }
  }
}

int main() {
  clock_t start, end;
  double cpu_time_used;

  start = clock();

  int qty = 100000, min_value = -100, max_value = 100;

  int arr[qty];

  srand(time(0));

  for (int i = 0; i < qty; i++) {
    arr[i] = randNumber(min_value, max_value);
  }

  printf("sorting array... \n");

  combSort(arr, qty);

  printf("sorted array\n");

  end = clock();
  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Execution time: %f\n", cpu_time_used);
}