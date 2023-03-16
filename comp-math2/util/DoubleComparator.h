//
// Created by moyak on 12.03.2023.
//

#ifndef COMP_MATH2_DOUBLECOMPARATOR_H
#define COMP_MATH2_DOUBLECOMPARATOR_H
#define ERROR 0.000001

#include <cmath>

namespace DoubleComparator {
    static bool double_equals(double a, double b) {
        return std::abs(a - b) < ERROR;
    }
}

#endif //COMP_MATH2_DOUBLECOMPARATOR_H
