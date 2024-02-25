#include <math.h>

#include "../../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = ok;
  matrix_t tmp = {0};

  // validation
  error |= incorrect_matrix * !s21_is_valid_matrix(A);
  error |= incorrect_matrix * (result == NULL);
  if (!error) error = calc_error * (A->rows != A->columns);
  if (!error) error = calc_error * (A->rows == 1);

  // init value
  if (!error)
    error = incorrect_matrix * s21_create_matrix(A->rows, A->columns, &tmp);

  // calculate value
  if (!error) {
    type_t det = 0;
    skip_indx_t indx = {0};

    for (size_t i = 0; i < (size_t)tmp.rows; i++) {
      for (size_t j = 0; j < (size_t)tmp.columns; j++) {
        indx.skip_col = j, indx.skip_row = i;
        error = s21_get_minor(A, &indx, &det);
        tmp.matrix[i][j] = det * pow(-1, i + j);
      }
    }

    if (!error) *result = tmp;
  }

  return error;
}