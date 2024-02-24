#include "s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Умножение 2 матриц

  @param[in] *A указатель на матрицу
  @param[in] *B указатель на матрицу
  @param[in] *result указатель на матрицу
  @return 0 - OK
  @return 1 - Ошибка, некорректная матрица
  @return 2 - Ошибка вычисления
*/
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = ok;

  error |= !s21_is_valid_matrix(A);
  error |= !s21_is_valid_matrix(B);
  error |= (result == NULL);

  if (!error) error = calc_error * (A->columns != B->rows);
  if (!error)
    error = calc_error * s21_create_matrix(A->rows, B->columns, result);

  for (size_t i = 0; !error && i < (size_t)A->rows; i++)
    for (size_t j = 0; j < (size_t)B->columns; j++)
      for (size_t k = 0; k < (size_t)A->columns; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];

  return error;
}