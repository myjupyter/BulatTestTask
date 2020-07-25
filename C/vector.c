#include "vector.h"

#include "stdlib.h"
#include "time.h"

int init_vec(Vector* vec, size_t size) {
    if (vec == NULL || vec->data != NULL) {
        return -1;
    }

    vec->data = calloc(sizeof(double), size);
    if (vec->data == NULL) {
        return -1;
    }
    vec->size = size;
    return 0;
}

void free_vec(Vector* vec) {
    if (vec == NULL || vec->data == NULL) {
        return;
    }
    free(vec->data);
}

int set_random_vec(Vector* vec) {
    if (vec == NULL || vec->data == NULL) {
        return -1;
    }
    for (size_t i = 0; i < vec->size; ++i) {
        vec->data[i] = rand() % 100 - 50 + 0.01 * (rand() % 100);
    }
    return 0;
}
