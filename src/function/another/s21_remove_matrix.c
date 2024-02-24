#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Отчистка матрицы

  @param[in] *A Указатель на матрицу
*/
void s21_remove_matrix(matrix_t *A) {
  if (s21_is_valid_matrix(A)) {
    for (size_t i = 0; i < (size_t)A->rows; i++)
      if (*(A->matrix + i)) free(*(A->matrix + i));

    free(A->matrix); 
  }
}