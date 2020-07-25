#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "matrix.h"

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (argc < 3) {
        fprintf(stderr,"./<program> <inputfile> <outputfile>");
        return -1;
    }
    
    FILE* in = fopen(argv[1], "r");
    if (in == NULL) {
        perror("fopen()");
        goto error_handle_1;
    }
    FILE* out = fopen(argv[2], "w");
    if (out == NULL) {
        perror("fopen()");
        fclose(in);
        goto error_handle_1;
    }

    size_t n = 0, m = 0;
    if (fscanf(in, "%ld %ld", &n, &m) != 2) {
        perror("fscanf()");
        goto error_handle_2;
    }

    Matrix mat = {};
    if (init_matrix(&mat, n, m)) {
        perror("init_matrix()");
        goto error_handle_2;
    }

    set_random_matrix(&mat);

    Matrix t = {};
    if (transp_matrix(&mat, &t)) {
        perror("transp_matrix()");
        goto error_handle_2;
    }

    if (write_as_csv(out, &t)) {
        perror("write_as_csv()");
        goto error_handle_2;
    }

    free_matrix(&mat);
    free_matrix(&t);
    fclose(in);
    fclose(out);
    return 0;

error_handle_2:
    fclose(in);
    fclose(out);
error_handle_1:
    return -1;

}
