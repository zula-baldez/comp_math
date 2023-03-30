//
// Created by moyak on 30.03.2023.
//

#include "TrapezoidMethod.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

double eps = 0.00001;

double get_mid(const std::function<double(double)> &func, double left, double right) {
    return left - (right - left) * func(left) / (func(right) - func(left));

}

double TrapezoidMethod::integrate(const std::function<double(double)> &func, double l_global, double r_global) {
    if(r_global  < l_global) return 0;
    double left = l_global;
    double right = std::min(r_global, l_global + eps);
    double integral = 0;
    while (left < r_global) {
        if (func(right) >= 0 && func(left) >= 0) {
            integral += (right - left) * std::abs(func(right) + func(left)) / 2;
        } else if (func(right) <= 0 && func(left) <= 0) {
            integral -= (right - left) * std::abs(func(right) + func(left)) / 2;

        } else {
            double x = left + get_mid(func, left, right);
            integral += func(left) * (x - left) / 2 + func(right) * (right - x) / 2;
        }
        left = right;
        right = std::min(r_global, right + eps);
    }
    return integral;
}

double TrapezoidMethod::integrate_with_gap(const std::function<double(double)> &func, double l_global, double r_global,
                                           int strategy, double gap_point) {
    if(r_global  < l_global) return 0;
    double integral = 0;
    if (strategy == 1) {
        integral += half_of_integral(func, l_global, gap_point, gap_point);
        integral += half_of_integral(func, gap_point, r_global, gap_point);

    }
    if (strategy == 2) {

        integral += (func(gap_point + eps) + func(gap_point - eps)) / 2 * (2 * eps);
        integral += integrate(func, l_global, gap_point-eps);
        integral += integrate(func, gap_point+eps, r_global);
    }
    return integral;

}



double TrapezoidMethod::half_of_integral(const std::function<double(double)> &func, double l_global, double r_global, double gap_point) {
    if(r_global  < l_global) return 0;
    double left = l_global;
    double right = std::min(r_global, l_global + eps);
    double integral = 0;

    while (left < r_global) {

        double func_l;
        if (left != gap_point) {
            func_l = func(left);
        } else {
            func_l = func(left + eps);
        }
        double func_r;
        if (right != gap_point) {
            func_r = func(right);
        } else {
            func_r = func(right - eps);
        }
        if (func_r >= 0 && func_l >= 0) {
            integral += (right - left) * std::abs(func_r + func_l) / 2;
        } else if (func_r <= 0 && func_l <= 0) {
            integral -= (right - left) * std::abs(func_r + func_l) / 2;

        } else {
            double x = left + get_mid(func, left, right);
            integral += func_l * (x - left) / 2 + func_r * (right - x) / 2;
        }
        left = right;
        right = std::min(r_global, right + eps);
    }
    return integral;
}
