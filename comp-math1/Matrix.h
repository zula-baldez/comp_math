//
// Created by moyak on 17.02.2023.
//

#ifndef UNTITLED8_MATRIX_H
#define UNTITLED8_MATRIX_H

#include "Row.h"
class Matrix {
public:
    Matrix() = default;

    Matrix(int n);

    void set_data(std::vector<Row> data) {
        m_data = std::move(data);
    }

protected:
    std::vector<Row> m_data;
};


#endif //UNTITLED8_MATRIX_H
