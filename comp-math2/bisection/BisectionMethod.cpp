//
// Created by moyak on 12.03.2023.
//

#include "BisectionMethodImpl.h"
#include "../util/DoubleComparator.h"
#include "../util/AnsStruct.h"
Ans BisectionMethodImpl::get_root(const std::function<double(double)> &func, double left, double right) {
    if (func(left) * func(right) >= 0) {
        return not_success;
    }
    double mid = (left + right) / 2;
    while (!DoubleComparator::double_equals(func(mid), 0.0)) {
        if (func(mid) * func(left) < 0) {
            right = mid;
        } else {
            left = mid;
        }
        mid = (left + right) / 2;
    }
    return Ans{true, mid};
}
