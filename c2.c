#include <stdio.h>

#define ARR_SIZE 3

int main(void) {
  int arr[] = {1, 2, 3};

  int max = 0;
  ;
  int min = 1e6;
  float avg = 0;
  float sum = 0;

  for (int idx = 0; idx < ARR_SIZE; ++idx) {
    if (arr[idx] > max) {
      max = arr[idx];
    }

    if (arr[idx] < min) {
      min = arr[idx];
    }

    sum += arr[idx];
  }

  avg = sum / ARR_SIZE;

  printf("max: %d, min: %d, sum: %.0f, avg: %f", max, min, sum, avg);
}
