#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief Создает матрицу задоного размера

  @param[in] rows Кол-во строк
  @param[in] columns Кол-во столбцов
  @param[in] result Указатель на результат
  @return 0 - OK 1 - ошибка вычисления
*/
int s21_inverse_matrix(matrix_t *A, matrix_t *result);