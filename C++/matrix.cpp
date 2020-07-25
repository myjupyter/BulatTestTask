#include "matrix.h"

#include <algorithm>
#include <cstdlib>

Matrix::Matrix(std::size_t n, std::size_t m) 
    : matrix_(n, vectord_t(m, 0)) {
    std::for_each(matrix_.begin(), matrix_.end(), [](auto& vec) {
        std::for_each(vec.begin(), vec.end(), [](auto& x) {
            x = rand() % 100 - 50 + 0.01 * (rand() % 100);
        });        
    });
}

std::ofstream& operator<<(std::ofstream& of, const Matrix& mat) {
    for (std::size_t i = 0; i < mat.matrix_.size(); ++i) {
        for (std::size_t j = 0; j < mat.matrix_[0].size(); ++j) {
            of << mat.matrix_[i][j] << ',';
        }
        of << std::endl;
    }
    return of;
}

Matrix Matrix::transp() const {
    if (matrix_.size() == 0 || matrix_[0].size() == 0) {
        throw std::runtime_error("transp(): Wrong matrix size!");
    }

    Matrix transp_mat(matrix_[0].size(), matrix_.size());
    for (std::size_t i = 0; i < matrix_.size(); ++i) {
        for (std::size_t j = 0; j < matrix_[0].size(); ++j) {
            transp_mat.matrix_[j][i] = matrix_[i][j];
        }
    }
    return transp_mat;
}



