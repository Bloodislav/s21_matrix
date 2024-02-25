#include "../../s21_matrix.h"

int s21_copy_matrix(matrix_t *src, matrix_t *dest) {
  uint16_t error = 0;

  error |= ((src == NULL) || (src->matrix == NULL));
  error |= ((dest == NULL) || (dest->matrix == NULL));

  for (int i = 0; !error && i < src->columns; i++)
    for (int j = 0; j < src->rows; j++) dest->matrix[i][j] = src->matrix[i][j];

  return error;
}

int s21_get_minor(matrix_t *src, skip_indx_t *skip, double *res) {
  int error = 0;
  matrix_t tmp = {0};

  error |= incorrect_matrix * !s21_is_valid_matrix(src);
  error |= (res == NULL);
  error |= (skip == NULL);

  if (!error) error = s21_create_matrix(src->rows - 1, src->columns - 1, &tmp);

  for (size_t i = 0; !error && i < (size_t)src->rows; i++) {
    if (i != skip->skip_row) {
      for (size_t j = 0; j < (size_t)src->columns; j++)
        if (j != skip->skip_col)
          tmp.matrix[i - (i > skip->skip_row)][j - (j > skip->skip_col)] =
              src->matrix[i][j];
    }
  }

  if (!error) error = s21_determinant(&tmp, res);

  s21_remove_matrix(&tmp);

  return error;
}