#include "../s21_matrix.h"

int sign(int rows, int columns) {
  int return_value = 1;
  if ((rows + columns) % 2) {
    return_value = -1;
  }
  return return_value;
}

void get_mini(const matrix_t* A, int row_ex, int col_ex, matrix_t* result) {
  int row_result = 0;
  for (int row = 0; row < A->rows; ++row) {
    if (row == row_ex) {
      continue;
    }
    int column_result = 0;
    for (int column = 0; column < A->columns; ++column) {
      if (column == col_ex) {
        continue;
      }
      result->matrix[row_result][column_result] = A->matrix[row][column];
      ++column_result;
    }
    ++row_result;
  }
}