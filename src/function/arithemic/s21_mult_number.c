#include "s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Умножение матрицы на число

  @param[in] *A указатель на матрицу
  @param[in] number число на которе домножаем
  @param[in] *result указатель на матрицу
  @return 0 - OK
  @return 1 - Ошибка, некорректная матрица
  @return 2 - Ошибка вычисления
*/
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = ok;

  error |= !s21_is_valid_matrix(A);
  error |= (result == NULL);

  if (!error)
    error = calc_error * s21_create_matrix(A->rows, A->columns, result);

  for (size_t i = 0; !error && i < (size_t)A->rows; i++)
    for (size_t j = 0; !error && j < (size_t)A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] * number;

  return error;
}