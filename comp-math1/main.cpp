#include <locale>
#include <iostream>
#include <fstream>

#include "MatrixWithGauss.h"

struct comma_decimal_separator : std::numpunct<char>
{
protected:
    char do_decimal_point() const override
    {
        return ',';
    }
};


int main() {
    std::cin.imbue(std::locale(std::locale(), new comma_decimal_separator));
    std::cout << "enter 1 if you want to use console" << std::endl;

    std::cout << "enter 2 if you want to use random" << std::endl;

    std::cout << "enter 3 if you want to use file" << std::endl;
    int dec;
    std::cin >> dec;

    if (dec == 1) {
        MatrixWithGauss mtrx;
        mtrx.solve_gauss(std::cin, std::cout);
    }
    if (dec == 2) {
        int size;
        std::cout << "enter size" << std::endl;
        std::cin >> size;
        MatrixWithGauss mtrx(size);
        mtrx.solve_gauss(std::cin, std::cout);
    }
    if (dec == 3) {
        std::cout << "enter file path with matrix" << std::endl;
        std::string path;
        std::cin >> path;
        std::ifstream in(path);
        if (!in.is_open()) {
            std::cout << "wrong file";
            return 1;
        }
        std::cout << "enter file path to output" << std::endl;
        std::string log_file;
        std::cin >> log_file;
        std::ofstream out;
        out.open(log_file);
        if (!out.is_open()) {
            std::cout << "wrong file";
            return 1;
        }
        in.imbue(std::locale(std::locale(), new comma_decimal_separator));
        MatrixWithGauss mtrx;
        mtrx.solve_gauss(in, out);
    }



}
