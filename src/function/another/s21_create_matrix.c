#include <stdint.h>
#include <stdlib.h>

#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Создает матрицу задоного размера

  @param[in] rows Кол-во строк
  @param[in] columns Кол-во столбцов
  @param[in] result Указатель на результат
  @return 0 - OK 1 - ошибка вычисления
*/
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  uint16_t error = 0;
  size_t error_index = 0;
  void **large_ptr = NULL, *small_ptr = NULL;

  // first validation
  error |= (rows <= 0) || (columns <= 0) || (result == NULL);

  // init first pointer & check error
  if (!error) {
    large_ptr = calloc(rows, sizeof(void *));
    error |= (large_ptr == NULL);
  }

  // set value to matrix
  if (!error) {
    result->matrix = (type_t **)large_ptr;
    result->rows = rows;
    result->columns = columns;
  }

  // init array to matrix value
  for (size_t i = 0; !error && i < (size_t)rows; i++) {
    small_ptr = calloc(columns, SIZE);
    if (!small_ptr) {
      error = 2;
      error_index = i;
    }
    if (!error) *(result->matrix + i) = (type_t *)small_ptr;
  }

  // if an error occurred in the previous cycle
  for (size_t j = 0; error == 2 && j < error_index; j++) {
    free(*(result->matrix + j));
    if (j + 1 == error_index) free(result->matrix);
  }
  error = (error != 2) * error;

  return error;
}