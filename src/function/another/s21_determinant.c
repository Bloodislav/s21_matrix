#include <math.h>

#include "../../s21_matrix.h"

void copy_matrix(matrix_t *src, matrix_t *dest);
double determinant_by_Gauss(matrix_t *A);
int rowsChange(matrix_t *A, int oldRow);

// GOOD
int s21_determinant(matrix_t *A, double *result) {
  int error = ok;

  error |= incorrect_matrix * !s21_is_valid_matrix(A);
  error |= incorrect_matrix * (result == NULL);
  if (!error) error |= calc_error * (A->rows != A->columns);

  if (!error) {
    matrix_t copyA = {0};
    s21_create_matrix(A->rows, A->columns, &copyA);
    copy_matrix(A, &copyA);

    *result = determinant_by_Gauss(&copyA);
    error = calc_error * (isnan(*result) || isinf(*result));

    s21_remove_matrix(&copyA);
  }

  return error;
}

// 50 / 50
void copy_matrix(matrix_t *src, matrix_t *dest) {
  for (int i = 0; i < src->columns; i++) {
    for (int j = 0; j < src->rows; j++) {
      dest->matrix[i][j] = src->matrix[i][j];
    }
  }
}

// BAD
double determinant_by_Gauss(matrix_t *A) {
  // знак определителя 0 - если полпожительно, 1 - если надо доп сменить
  int sign = 0;
  double result = 1;

  for (int i = 0; i < A->rows && result; i++) {
    // смена строк если у неа нулевой элемент
    if (A->matrix[i][i] == 0) {
      if (rowsChange(A, i))
        sign = !sign;
      else
        result = 0;
    }
    // приведение к нулю
    for (int j = i + 1; j < A->rows && result; j++) {
      if (A->matrix[j][i] != 0) {
        double coefficient = A->matrix[j][i] / A->matrix[i][i];
        for (int k = i; k < A->rows; k++)  // проход по всей строке
          A->matrix[j][k] = A->matrix[j][k] - A->matrix[i][k] * coefficient;
      }
    }
  }
  if (result)
    for (int i = 0; i < A->rows; i++) result *= A->matrix[i][i];

  return pow(-1, sign) * result;
}

// 50 / 50
int rowsChange(matrix_t *A, int oldRow) {
  int status = 0;

  for (int newRow = oldRow + 1; newRow < A->rows && !status; newRow++) {
    status = (A->matrix[newRow][oldRow] != 0);
    for (int k = oldRow; status && k < A->rows; k++) {
      double temp = A->matrix[oldRow][k];
      A->matrix[oldRow][k] = A->matrix[newRow][k];
      A->matrix[newRow][k] = temp;
    }
  }
  return status;
}