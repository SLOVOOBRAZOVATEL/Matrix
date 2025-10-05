#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!A || !B) return FAILURE;
  int return_value = SUCCESS;
  if (A->rows != B->rows || A->columns != B->columns) {
    return_value = FAILURE;
  }
  for (int i = 0; i < A->rows && return_value; i++) {
    for (int j = 0; j < A->columns && return_value; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) {
        return_value = FAILURE;
      }
    }
  }
  return return_value;
}