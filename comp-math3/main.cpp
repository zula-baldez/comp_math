#include <iostream>
#include <iomanip>
#include <cmath>

#include "trapezoid/TrapezoidMethod.h"


double function1(double x) {
    return x * x + 2 * x + 1;
}

double function2(double x) {
    return sin(x) * cos(x);
}

double function3(double x) {
    return sin(x) / x;
}


int main() {
    TrapezoidMethod tm = TrapezoidMethod();
    std::function<double(double)> f1 = function1;
    std::function<double(double)> f2 = function2;
    std::function<double(double)> f3 = function3;

    std::cout << "What equation you want to integrate:\n" <<
              "1: x^2 + 2*x + 1\n" <<
              "2: sin(x)*cos(x)\n" <<
              "3: sin(x)/x";
    int eq;
    std::cin >> eq;
    std::cout << "enter left boundary" << std::endl;
    double l;
    std::cin >> l;
    std::cout << "enter right boundary" << std::endl;
    double r;
    std::cin >> r;
    std::cout << std::setprecision(15);
    std::cout << std::fixed;

    if (eq == 1) {
        std::cout << tm.integrate(f1, l, r) << std::endl;
    }

    if (eq == 2) {
        std::cout << tm.integrate(f2, l, r) << std::endl;
    }

    if (eq == 3) {
        if (l <= 0 && r >= 0) {
            std::cout
                    << "this func has gaps! if you want to find the value to the right and left of the point and add type 1\n"
                    <<
                    "if you want to find mean of the value from two neighboring points of the function x - e, x + e, type 2"
                    << std::endl;
            int strategy;
            std::cin >> strategy;
            std::cout << tm.integrate_with_gap(f3, l, r, strategy, 0) << std::endl;

        }  else {
            std::cout << tm.integrate(f3, l, r) << std::endl;

        }
    }


}
