#ifndef MATRIX_H_
#define MATRIX_H_

#include "stdio.h"

#include "vector.h"

typedef struct Matrix {
    size_t n;
    Vector* vec_data;
} Matrix;

int init_matrix(Matrix* mat, size_t n, size_t m);
void free_matrix(Matrix* mat);
int set_random_matrix(Matrix* mat);
int transp_matrix(const Matrix* mat, Matrix* transp_mat);
int write_as_csv(FILE* out, const Matrix* mat);

#endif  // MATRIX_H_
