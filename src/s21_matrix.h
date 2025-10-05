#ifndef S_21_MATRIX
#define S_21_MATRIX

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL ((void *)0)

typedef enum {
  OK = 0,
  INCORRECT_MATRIX = 1,
  CALC_ERROR = 2,
  MALLOC_FAIL = 3
} return_code;

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns,
                      matrix_t *result);  // создание матрицы
void s21_remove_matrix(matrix_t *A);      // очистка матрицы

#define SUCCESS 1
#define FAILURE 0

int s21_eq_matrix(matrix_t *A, matrix_t *B);  // сравнение, 6 знаков после ,

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);

int s21_calc_complements(matrix_t *A, matrix_t *result);

int s21_determinant(matrix_t *A, double *result);

int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif