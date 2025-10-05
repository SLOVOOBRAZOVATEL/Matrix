#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!A || !result) {
    return INCORRECT_MATRIX;
  }
  int return_value = 0;
  if (s21_create_matrix(A->rows, A->columns, result)) {
    return_value = MALLOC_FAIL;
  }
  if (!return_value) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return return_value;
}