#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!A || !result) {
    return INCORRECT_MATRIX;
  }

  int return_value = 0;
  double det = 0;
  s21_determinant(A, &det);
  if (A->columns != A->rows || det == 0) {
    return_value = CALC_ERROR;
  }
  if (!return_value) {
    if (s21_create_matrix(A->columns, A->rows, result) != 0) {
      return_value = MALLOC_FAIL;
    } else {
      matrix_t T = {0};
      s21_calc_complements(A, result);
      s21_transpose(result, &T);
      s21_mult_number(&T, 1.0 / det, result);
      s21_remove_matrix(&T);
    }
  }
  return return_value;
}
