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
  
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);
  m.matrix[0][0] = 2;
  m.matrix[0][1] = 3;
  m.matrix[0][2] = 1;
  m.matrix[1][0] = 7;
  m.matrix[1][1] = 4;
  m.matrix[1][2] = 1;
  m.matrix[2][0] = 9;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = 1;

  double res = 0, det = -32;
  int code = s21_determinant(&m, &res), check_code = 0;
  
  print_matrix(&m, "res");
  
  printf("res: %lf\n", res);
  printf("det: %lf\n", det);

  printf("      code: %d\n", code);
  printf("check_code: %d\n", check_code);

  s21_remove_matrix(&m);

  return 0;
}