#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Проверка на валидность

  @param[in] *A указатель на матрицу
  @param[in] *B указатель на матрицу
  @return 1 - True
  @return 0 - False
*/
int s21_is_valid_matrix(matrix_t *A) {
  return (A != NULL && A->matrix != NULL && A->columns > 0 && A->rows > 0);
}