//
// Created by moyak on 17.02.2023.
//


#include <random>
#include "Matrix.h"


Matrix::Matrix(int n) {
    std::vector<Row> rows;
    std::vector<double> row_data(n+1);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-10.0, 10.0);
    for(int row = 1; row <= n; row++) {
        row_data.clear();
        for (int col = 1; col <= n + 1; col++) {
            row_data.push_back(dist(gen));
        }
        Row random_raw = Row(row_data);
        rows.push_back(random_raw);

    }
    set_data(rows);
}



