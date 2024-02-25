#include <math.h>

#include "../../s21_matrix.h"

/*!
  @ingroup MatrixFunc Функции над матрицами
  @brief 

  @param[in] result Указатель на результат
  @return 0 - OK 1 - ошибка вычисления
*/
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = ok;

  // first valid
  error = incorrect_matrix * !s21_is_valid_matrix(A);
  // secomd valid
  if (!error) error = calc_error * (A->rows != A->columns);
  if (!error) error = calc_error * (A->rows == 1);
  
  // Clculate inverce
  if (!error) {
    type_t det = 0;
    matrix_t calc_comp = {0}, transpose = {0};

    // 1. Поиск определителя:
    error = s21_determinant(A, &det);
    // Определитель |A| != 0 -> обратная матрица существует
    if (!error) error |= (fabs(det) < PRECISION);

    // 2. Построение матрицы алгебраических дополнений:
    if (!error) error |= s21_transpose(A, &transpose);
    
    // 3. Транспонированная матрица 
    if (!error) error |= s21_calc_complements(&transpose, &calc_comp);

    // 4. mul to num
    if (!error) error |= s21_mult_number(&calc_comp, 1 / det, result);

    error = calc_error * (!!error);

    s21_remove_matrix(&calc_comp);
    s21_remove_matrix(&transpose);
  }

  return error;
}