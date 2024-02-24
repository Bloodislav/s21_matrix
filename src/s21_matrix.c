#include "s21_matrix.h"

#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_matrix(matrix_t *matrix, char *text) {
  printf("\x1b[1;33m-=%s=-\x1b[0m\n", text);
  for (size_t i = 0; i < (size_t)matrix->rows; i++) {
    for (size_t j = 0; j < (size_t)matrix->columns; j++)
      printf("[%ld, %ld]: %lf ", i, j, *(*(matrix->matrix + i) + j));
    printf("\n");
  }
}

int main() {
  matrix_t A = {0};
  int rows = 3, columns = 3, error = 0;

  error = s21_create_matrix(rows, columns, &A);
  printf("error: %d\n", error);
  print_matrix(&A, "Matrix A");
  s21_remove_matrix(&A);

  return 0;
}