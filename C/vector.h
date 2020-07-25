#ifndef VECTOR_H_
#define VECTOR_H_

#include <stddef.h>

typedef struct Vector {
    size_t size;
    double* data;
} Vector;

int init_vec(Vector* vec, size_t size);
void free_vec(Vector* vec);
int set_random_vec(Vector* vec);

#endif  // VECTOR_H_
