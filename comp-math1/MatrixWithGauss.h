//
// Created by moyak on 28.02.2023.
//

#ifndef UNTITLED8_MATRIXWITHGAUSS_H
#define UNTITLED8_MATRIXWITHGAUSS_H


#include "Matrix.h"

class MatrixWithGauss : public Matrix {
public:
    MatrixWithGauss() : Matrix() {};

    explicit MatrixWithGauss(int n) : Matrix(n) {}

    void read_matrix_inp(std::istream& in, std::ostream& out);

    void triangulation();

    void normalize();

    void solve_gauss(std::istream& in, std::ostream& out);

    double determinant_in_triangulated();

    void print_matrix(std::ostream& out);

    std::vector<double> get_ans();

    std::vector<double> get_nevyaska(std::vector<double> ans, MatrixWithGauss& matrix);
};


#endif //UNTITLED8_MATRIXWITHGAUSS_H
