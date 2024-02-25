#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <endian.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define PRECISION 1e-7

typedef double type_t;

#define SIZE sizeof(type_t)

typedef struct matrix_struct {
  type_t **matrix;
  int rows;
  int columns;
} matrix_t;

typedef struct skip_indx_struct {
  size_t skip_row;
  size_t skip_col;
} skip_indx_t;

enum error { ok = 0, incorrect_matrix = 1, calc_error = 2 };

/*!
  @defgroup MatrixFunc Функции над матрицами
  @brief Модуль операций над matrix_t

  @return 0 - OK
  @return 1 - Ошибка, некорректная матрица
  @return 2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для
  которой нельзя провести вычисления и т.д.)
*/

/**************************************************************************/
/*                    ANOTHER                                             */
/**************************************************************************/
int s21_create_matrix(int rows, int columns, matrix_t *result);  // | + |
void s21_remove_matrix(matrix_t *A);                             // | + |
int s21_transpose(matrix_t *A, matrix_t *result);                // | + |
int s21_calc_complements(matrix_t *A, matrix_t *result);         // | - |
int s21_determinant(matrix_t *A, double *result);                // | - |
int s21_inverse_matrix(matrix_t *A, matrix_t *result);           // | - |
/**************************************************************************/

/**************************************************************************/
/*                    COMPARE                                             */
/**************************************************************************/
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_is_valid_matrix(matrix_t *A);
int s21_is_same_size(matrix_t *A, matrix_t *B);
/**************************************************************************/

/**************************************************************************/
/*                    ARITHMETIC                                          */
/**************************************************************************/
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // | + |
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // | + |
int s21_mult_number(matrix_t *A, double number, matrix_t *result);  // | + |
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);    // | + |
/**************************************************************************/

/**************************************************************************/
/*                    SUPPORT                                             */
/**************************************************************************/
int s21_swap_rows(matrix_t *A, int row_index);
int s21_copy_matrix(matrix_t *src, matrix_t *dest);
int s21_get_minor(matrix_t *src, skip_indx_t *skip, double *res);
/**************************************************************************/

void print_matrix(matrix_t *matrix, char *text);
#endif