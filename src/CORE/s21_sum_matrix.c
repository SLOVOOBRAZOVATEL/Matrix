#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int return_value = 0;
  if (!A || !B || !result) {
    return_value = INCORRECT_MATRIX;
  }
  if (!return_value && (A->rows != B->rows || A->columns != B->columns)) {
    return_value = CALC_ERROR;
  }
  if (!return_value && s21_create_matrix(A->rows, A->columns, result)) {
    return_value = MALLOC_FAIL;
  }
  if (!return_value) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return return_value;
}
