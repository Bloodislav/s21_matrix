#include <math.h>

#include "../../s21_matrix.h"

int s21_swap_rows(matrix_t *A, int row_index) {
  int status = 0;
  type_t *tmp = 0;

  status |= calc_error * (A == NULL || A->matrix == NULL);

  for (size_t i = row_index + 1; !status && i < (size_t)A->rows; i++) {
    status = (fabs(A->matrix[i][row_index]) >= PRECISION);
    if (status) {
      tmp = A->matrix[row_index];
      A->matrix[row_index] = A->matrix[i];
      A->matrix[i] = tmp;
    }
  }

  return status;
}