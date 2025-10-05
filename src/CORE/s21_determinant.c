#include "../s21_common.h"
#include "../s21_matrix.h"

static double det_mini(double a00, double a01, double a10, double a11) {
  return a00 * a11 - a01 * a10;
}

static double det(const matrix_t* A) {
  double ret_val = 0.0;
  if (A->rows == 1) {
    ret_val = A->matrix[0][0];
  } else if (A->rows == 2) {
    ret_val = det_mini(A->matrix[0][0], A->matrix[0][1], A->matrix[1][0],
                       A->matrix[1][1]);
  } else {
    matrix_t M;

    if (!s21_create_matrix(A->rows - 1, A->columns - 1, &M)) {
      for (int col = 0; col < A->columns; col++) {
        get_mini(A, 0, col, &M);
        ret_val += ((A->matrix[0][col]) * sign(0, col) * det(&M));
      }
    }
    // } else {
    //   ret_val = MALLOC_FAIL;
    // }
    s21_remove_matrix(&M);
  }
  return ret_val;
}

int s21_determinant(matrix_t* A, double* result) {
  if (!A || !result) {
    return INCORRECT_MATRIX;
  }
  int return_value = 0;
  if (!return_value && (A->rows == A->columns)) {
    *result = det(A);
  } else {
    return_value = CALC_ERROR;
  }
  return return_value;
}