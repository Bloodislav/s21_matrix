#include <math.h>

#include "../../s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error = ok;

  // validation
  error |= incorrect_matrix * !s21_is_valid_matrix(A);
  error |= incorrect_matrix * (result == NULL);
  if (!error) error |= calc_error * (A->rows != A->columns);

  // calculating
  if (!error) {
    // init value
    uint8_t sign = 0, swap = 3;
    double factor = 0, tmp_res = 0;
    matrix_t tmp = {0};

    error = s21_create_matrix(A->rows, A->columns, &tmp);

    // set value
    if (!error) {
      error = s21_copy_matrix(A, &tmp);
      tmp_res = !error;
    }

    for (size_t i = 0; tmp_res && i < (size_t)tmp.rows; i++) {
      // if tmp.matrix[i][i] == 0
      if (!tmp.matrix[i][i]) {
        swap = s21_swap_rows(&tmp, i);
        error = (swap == 2);
      }

      // if dont swap rows or have calculating error
      if (!error && !swap) tmp_res = 0;

      // if swap rows
      else if (swap == 1) {
        sign = !sign;
      }

      for (size_t j = i + 1; tmp_res && j < (size_t)tmp.columns; j++) {
        factor = tmp.matrix[j][i] / tmp.matrix[i][i];
        for (size_t k = i; factor && k < (size_t)tmp.columns; k++)
          tmp.matrix[j][k] -= tmp.matrix[i][k] * factor;
      }
    }

    // calculate determinant
    for (size_t i = 0; !error && tmp_res && i < (size_t)A->rows; i++)
      tmp_res *= tmp.matrix[i][i];

    // check error
    if (!error) error = calc_error * (isnan(tmp_res) || isinf(tmp_res));

    // export
    if (!error) *result = (1 - 2 * sign) * tmp_res;

    // remove tmp
    s21_remove_matrix(&tmp);
  }

  return error;
}
