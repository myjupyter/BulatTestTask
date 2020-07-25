#include <iostream>

#include "matrix.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << std::string(argv[0]) + " <inputfile> <outputfile>" << std::endl;
        return 1;
    }
    try { 
        std::ifstream in(argv[1]);
        std::ofstream out(argv[2]);

        std::size_t n = 0, m = 0;
        in >> n >> m;
        if (in.fail()) {
            std::cerr << std::string(argv[1]) + " has wrong format!" << std::endl;
            return 1;
        }

        Matrix mat(n, m);
        out << mat.transp();

    } catch (std::exception& exce) {
        std::cerr << exce.what() << std::endl;
    }
    return 0;
}
