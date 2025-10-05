#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  if (rows < 1 || columns < 1 || !result) {
    return INCORRECT_MATRIX;
  }

  int return_value = 0;
  result->rows = rows;
  result->columns = columns;

  result->matrix = (double**)calloc(rows, sizeof(double*));

  if (result->matrix) {
    for (int i = 0; i < rows && !return_value; i++) {
      result->matrix[i] = (double*)calloc(columns, sizeof(double));
    }
  } else {
    return_value = MALLOC_FAIL;
  }

  return return_value;
}