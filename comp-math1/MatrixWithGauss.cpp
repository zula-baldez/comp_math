//
// Created by moyak on 28.02.2023.
//

#include "MatrixWithGauss.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>

#define ERROR 0.00001

bool equals(double a, double b) {
    if (std::abs(a - b) < ERROR) {
        return true;
    }
    return false;
}

void MatrixWithGauss::read_matrix_inp(std::istream &in, std::ostream & out) {
    out<<"enter n"<<std::endl;

    int n;
    in >> n;
    out<<"enter n rows and n+1 columns"<<std::endl;

    for (int i = 1; i <= n; i++) {
        Row row;
        for (int j = 1; j <= n + 1; j++) {
            double num;
            in >> num;
            row.add(num);
        }
        m_data.push_back(row);
    }
}



void MatrixWithGauss::triangulation() {
    for (int j = 0; j < m_data.size() - 1; j++) {
        for (int row_index = j; row_index < m_data.size(); row_index++) {
            if (!equals(m_data[row_index][j], 0)) {
                if (row_index != j) {
                    m_data[j] = m_data[row_index] + m_data[j];
                }
                break;

            }
        }
        if (m_data[j][j] == 0) continue;
        for (int i = j + 1; i < m_data.size(); i++) {
            double koef = (double) m_data[i][j] / m_data[j][j];
            m_data[i] = m_data[i] - m_data[j] * koef;
        }
    }
}

void MatrixWithGauss::normalize() {
    for (int i = 0; i < m_data.size(); i++) {
        if(m_data[i][i] != 0)
        m_data[i] = m_data[i] / m_data[i][i];
    }
}


std::vector<double> MatrixWithGauss::get_ans() {
    std::vector<double> ans(m_data.size());
    int row_len = (int) m_data[0].get_size();
    for (int row_idx = (int) m_data.size() - 1; row_idx >= 0; row_idx--) {
        double x = m_data[row_idx][row_len-1];
        for (int column = row_len - 2; column > row_idx; column--) {
            x -= ans[column] * m_data[row_idx][column];
        }
        if (m_data[row_idx][row_idx] != 0) {
            ans[row_idx] = x / m_data[row_idx][row_idx];
        } else {
            ans.clear();
            return ans;
        }

    }
    return ans;
}

double MatrixWithGauss::determinant_in_triangulated() {
    double det = 1;
    for (int row_idx = 0; row_idx < m_data.size(); row_idx++) {
        det *= m_data[row_idx][row_idx];
    }
    return det;
}

void MatrixWithGauss::print_matrix(std::ostream &out) {
    for (auto & row_idx : m_data) {
        for (int column = 0; column < m_data[0].get_size(); column++) {
            out << std::fixed << std::setprecision(2) << std::setw(7) << row_idx[column];
        }
        out << std::endl;
    }
}

std::vector<double> MatrixWithGauss::get_nevyaska(std::vector<double> ans, MatrixWithGauss& matrix) {
    std::vector<double> nevyaska;
    for(auto & row : matrix.m_data) {
        double diff = 0;
        for (int column = 0; column < m_data[0].get_size() - 1; column++) {
            diff += row[column] * ans[column];
        }
        diff -= row[m_data[0].get_size() - 1];
        nevyaska.push_back(diff);
    }
    return nevyaska;
}


void MatrixWithGauss::solve_gauss(std::istream &in, std::ostream &out) {
    if(m_data.empty()) {
        read_matrix_inp(in, out);
    }
    auto start_time = std::chrono::high_resolution_clock::now();

    print_matrix(out);
    MatrixWithGauss old_matrix = *this;
    triangulation();
    out<<"triangulated---------"<<std::endl;
    print_matrix(out);
    double det = determinant_in_triangulated();
    out << "Determinant is: " << det << std::endl;
    normalize();

    std::vector<double> ans = get_ans();
    if(ans.empty()) {
        out<<"no solutions"<<std::endl;
    } else {
        out << "Answer is:" << std::endl;
        for (int idx = 0; idx < ans.size(); idx++) {
            out << 'x' << idx + 1 << ": " << ans[idx] << std::endl;
        }
        auto nevyaska = get_nevyaska(ans, old_matrix);
        out << "discrepancy------------" << std::endl;
        out << std::setprecision(20);
        for (int idx = 0; idx < nevyaska.size(); idx++) {
            out << idx + 1 << ": " << nevyaska[idx] << std::endl;
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    out << "Elapsed time: " << elapsed_time.count() << " ms" << std::endl;

}

