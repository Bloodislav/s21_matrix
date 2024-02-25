#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Сравнение размеров 2 матриц

  @param[in] *A указатель на матрицу
  @param[in] *B указатель на матрицу
  @return 1 - True
  @return 0 - False
*/
int s21_is_same_size(matrix_t *A, matrix_t *B) {
  return ((A != NULL && B != NULL) &&
          (A->rows == B->rows && A->columns == B->columns));
}