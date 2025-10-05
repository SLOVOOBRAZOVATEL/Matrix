#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || !B || !result) {
    return INCORRECT_MATRIX;
  }
  int return_value = 0;
  if (A->columns != B->rows) {
    return_value = CALC_ERROR;
  }
  if (!return_value && s21_create_matrix(A->rows, B->columns, result)) {
    return_value = MALLOC_FAIL;
  }
  if (!return_value) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < B->rows; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return return_value;
}
