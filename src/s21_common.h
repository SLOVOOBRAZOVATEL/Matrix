#ifndef S21_COMMON_H_
#define S21_COMMON_H_

#include "s21_matrix.h"

int sign(int rows, int columns);
void get_mini(const matrix_t *a, int row_to_exclude, int column_to_exclude,
              matrix_t *result);

#endif