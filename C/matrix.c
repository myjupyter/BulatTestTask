#include "matrix.h"

#include <stdlib.h>

int init_matrix(Matrix* mat, size_t n, size_t m) {
    if (mat == NULL || mat->vec_data != NULL) {
        return -1;
    }

    mat->n = 0;
    mat->vec_data = calloc(sizeof(Vector), n);
    if (mat->vec_data == NULL) {
        return -1;
    }

    for (;mat->n < n; ++(mat->n)) {
        if (init_vec(mat->vec_data + mat->n, m)) {
            goto error_handle;
        }
    }
    return 0;

error_handle:
    free_matrix(mat);
    return -1;
}

void free_matrix(Matrix* mat) {
    if (mat == NULL || mat->vec_data == NULL) {
        return;
    }
    for (size_t i = 0; i < mat->n; ++i) {
        free_vec(mat->vec_data + i);
    }
    free(mat->vec_data);
}

int set_random_matrix(Matrix* mat) {
    if (mat == NULL || mat->vec_data == NULL) {
        return -1;
    }
    for (size_t i = 0; i < mat->n; ++i) {
        if (set_random_vec(mat->vec_data + i)) {
            return -1;
        }
    }
    return 0;
}

int transp_matrix(const Matrix* mat, Matrix* transp_mat) {
    if (mat == NULL || mat->vec_data == NULL) {
        return -1;
    }
    size_t n = mat->n;
    size_t m = mat->vec_data[0].size;
    if (init_matrix(transp_mat, m, n)) {
        return -1;
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            transp_mat->vec_data[j].data[i] = mat->vec_data[i].data[j];
        }
    }
    return 0; 
}

int write_as_csv(FILE* out, const Matrix* mat) {
    if (out == NULL || mat == NULL || mat->vec_data == NULL) {
        return -1;
    }
    size_t n = mat->n;
    size_t m = mat->vec_data[0].size;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            fprintf(out, "%f,", mat->vec_data[i].data[j]);
        }
        fprintf(out, "\n");
    }
    return 0;
}
