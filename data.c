#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "random.h"
#include "config.h"

int main() {
  FILE *file;
  int i;

  // Open the file for writing
  file = fopen(FILENAME, "w");
  if (file == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  srand(time(0));

  // Generate and write 10 random numbers to the file
  for (i = 0; i < QUANTITY; i++) {
    fprintf(file, "%d\n", randNumber(MIN_VALUE, MAX_VALUE));
  }

  // Close the file
  fclose(file);

  printf("Random numbers generated and saved to %s\n", FILENAME);

  return 0;
}