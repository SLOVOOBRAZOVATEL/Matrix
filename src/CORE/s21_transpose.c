#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_value = 0;
  if (!A || !result) {
    return_value = INCORRECT_MATRIX;
  }
  if (!return_value && s21_create_matrix(A->columns, A->rows, result)) {
    return_value = MALLOC_FAIL;
  }
  if (!return_value) {
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  }
  return return_value;
}