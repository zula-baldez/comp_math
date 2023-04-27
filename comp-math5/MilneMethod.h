//
// Created by egor on 27.04.23.
//

#ifndef COMP_MATH5_MILNEMETHOD_H
#define COMP_MATH5_MILNEMETHOD_H

#include <bits/stdc++.h>


class MilneMethod {
public:
    std::pair<std::vector<double>, std::vector<double>>
    solveByMilne(std::function<double(double, double)> &f, double epsilon, double a, double y_a, double b);
};

#endif //COMP_MATH5_MILNEMETHOD_H
