#ifndef MATRIX_CPP
#define MATRIX_CPP

#include <vector>
#include <fstream>

using vectord_t = std::vector<double>;
using matrix_t = std::vector<vectord_t>;

class Matrix {
    public:
       explicit Matrix(std::size_t n, std::size_t m);
       Matrix transp() const;
       friend std::ofstream& operator<<(std::ofstream& of, const Matrix& mat);
    
    private:
        matrix_t matrix_;
};

#endif // MATRIX_CPP
