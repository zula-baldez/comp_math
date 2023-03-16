//
// Created by moyak on 12.03.2023.
//

#include "SecantMethod.h"
#include "../util/DoubleComparator.h"
double get_mid(const std::function<double(double)> &func, double left, double right) {
    if (func(left) < 0) {
        return left - (right - left) * func(left) / (func(right) - func(left));
    } else {
        return left + (right - left) * func(left) / (-func(right) + func(left));
    }
}
Ans SecantMethod::get_root(const std::function<double(double)> &func, double left, double right) {
    if (func(left) * func(right) >= 0) {
        return not_success;
    }
    double mid = get_mid(func, left, right);

    while(!DoubleComparator::double_equals(func(mid), 0)) {
        if(func(mid) * func(left) < 0) {
            right = mid;
        } else {
            left = mid;
        }
        mid = get_mid(func, left, right);
    }
    return Ans{true, mid};
}
