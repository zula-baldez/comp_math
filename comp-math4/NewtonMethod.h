//
// Created by egor on 13.04.23.
//

#ifndef COMP_MATH4_NEWTONMETHOD_H
#define COMP_MATH4_NEWTONMETHOD_H


#include <vector>

class NewtonMethod {
    double diff(std::vector<double> &x_axis, std::vector<double> &y_axis, int n);


public:
    std::vector<double> interpolate_by_newton(std::vector<double> x_axis, std::vector<double> y_axis);

    double calculate_in_point(std::vector<double> &coefficients, std::vector<double> &x_axis, double x);
};


#endif //COMP_MATH4_NEWTONMETHOD_H
