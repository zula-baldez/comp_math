//
// Created by moyak on 30.03.2023.
//

#ifndef COMP_MATH3_TRAPEZOIDMETHOD_H
#define COMP_MATH3_TRAPEZOIDMETHOD_H


#include <functional>
#include <vector>

class TrapezoidMethod {
public:
    double integrate(const std::function<double(double)>&, double l, double r);
    double integrate_with_gap(const std::function<double(double)>&, double l, double r, int strategy, double gap_point);


    static double half_of_integral(const std::function<double(double)> &func, double l_global, double r_global, double gap_point);
};


#endif //COMP_MATH3_TRAPEZOIDMETHOD_H
