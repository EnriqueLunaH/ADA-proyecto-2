#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randNumber(int min, int max) {
  srand(time(NULL));
  return (rand() % (max - min + 1)) + min;
}