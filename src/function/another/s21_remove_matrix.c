#include <stdint.h>
#include <stdlib.h>

#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Отчистка матрицы

  @param[in] *A Указатель на матрицу
*/
void s21_remove_matrix(matrix_t *A) {
  uint16_t error = 0;
  error = !((A != NULL) && (A->matrix != NULL) && (A->rows > 0) &&
            (A->columns > 0));

  if (!error) {
    for (size_t i = 0; i < (size_t)A->rows; i++)
      if (*(A->matrix + i)) free(*(A->matrix + i));

    free(A->matrix);  // free without if (A->matrix) becouse check in error
  }
}