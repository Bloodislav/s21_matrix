#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Транспонирование матрицы

  @param[in] *A Указатель на матрицу
  @param[in] *result Указатель на матрицу
  @return 0 - OK 1 - ошибка вычисления
*/
int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = ok;
  error = incorrect_matrix * !s21_is_valid_matrix(A);

  if (!error)
    error = calc_error * s21_create_matrix(A->columns, A->rows, result);

  for (size_t i = 0; !error && i < (size_t)result->rows; i++)
    for (size_t j = 0; j < (size_t)result->columns; j++)
      result->matrix[i][j] = A->matrix[j][i];

  return error;
}