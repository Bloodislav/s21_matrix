#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Вычитание 2 матриц

  @param[in] *A указатель на матрицу
  @param[in] *B указатель на матрицу
  @param[in] *result указатель на матрицу
  @return 0 - OK
  @return 1 - Ошибка, некорректная матрица
  @return 2 - Ошибка вычисления
*/
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = ok;

  error |= !s21_is_valid_matrix(A);
  error |= !s21_is_valid_matrix(B);
  error |= (result == NULL);

  if (!error) error = calc_error * s21_is_same_size(A, B);
  if (!error)
    error = calc_error * s21_create_matrix(A->rows, A->columns, result);

  for (size_t i = 0; !error && i < (size_t)A->rows; i++)
    for (size_t j = 0; !error && j < (size_t)A->columns; j++)
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];

  return error;
}