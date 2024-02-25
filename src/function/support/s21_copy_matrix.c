#include "../../s21_matrix.h"


int s21_copy_matrix(matrix_t *src, matrix_t *dest) {
  uint16_t error = 0;

  error |= ((src == NULL) || (src->matrix == NULL));
  error |= ((dest == NULL) || (dest->matrix == NULL));

  for (int i = 0; !error && i < src->columns; i++)
    for (int j = 0; j < src->rows; j++)
      dest->matrix[i][j] = src->matrix[i][j];
    
  return error;
}