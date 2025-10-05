#include "../s21_common.h"
#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!A || !result) {
    return INCORRECT_MATRIX;
  }
  int return_value = 0;
  if (A->rows != A->columns) {
    return_value = CALC_ERROR;
  }
  if (!return_value && s21_create_matrix(A->rows, A->columns, result)) {
    return_value = MALLOC_FAIL;
  }
  if (!return_value && A && (A->rows == 1)) {
    result->matrix[0][0] = 1.0;
    return_value = OK;
  } else if (A->rows >= 2 && !return_value) {
    matrix_t M = {0};
    if (!return_value && s21_create_matrix(A->rows - 1, A->columns - 1, &M)) {
      return_value = MALLOC_FAIL;
      s21_remove_matrix(result);
    } else {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          get_mini(A, i, j, &M);
          double det = 0.0;
          if (!s21_determinant(&M, &det)) {
            result->matrix[i][j] = sign(i, j) * det;
          }
        }
      }
    }
    s21_remove_matrix(&M);
  }
  return return_value;
}