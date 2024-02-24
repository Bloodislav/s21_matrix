#include <math.h>

#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Сравнение 2 матриц

  @param[in] *A указатель на матрицу
  @param[in] *B указатель на матрицу
  @return 1 - True
  @return 0 - False
*/
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  result = s21_is_valid_matrix(A) && s21_is_valid_matrix(B);

  if (result) result = s21_is_same_size(A, B);
  for (size_t i = 0; result && i < (size_t)A->rows; i++)
    for (size_t j = 0; result && j < (size_t)A->columns; j++) {
      result = (isinf(A->matrix[i][j]) && isinf(B->matrix[i][j]));
      if (!result) result = (isnan(A->matrix[i][j]) && isnan(B->matrix[i][j]));
      if (!result)
        result = (fabsl(A->matrix[i][j] - B->matrix[i][j])) < PRECISION;
    }
  return result;
}