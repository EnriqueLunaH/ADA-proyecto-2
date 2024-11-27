#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}