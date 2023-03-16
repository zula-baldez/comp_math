#include <iostream>
#include <cmath>
#include <functional>
#include "bisection/BisectionMethodImpl.h"
#include "iterations/IterationMethod.h"
#include "secant/SecantMethod.h"

double polynomyal(double x) {
    return pow(x, 3) + 4 * pow(x, 2) - 10;
}

double log_func(double x) {
    return log10(x) + log2(x) - 5;
}

double trigonometrical_func(double x) {
    return 5 * sin(x) + 4 * cos(x) - 1;
}

// 2^x1^2 - x1x2 - 5x1 + 1 = 0
// x1 + 3 lgx1 - x2^2 = 0
// x3 = 15*x1 +  16*x2;
double func1_system(std::vector<double> variables) {
    return sqrt((variables[0] * (variables[1] + 5) - 1) / 2.0);

}

double func2_system(std::vector<double> variables) {
    return sqrt(variables[0] + 3 * log10(variables[0]));
}

double func3_system(std::vector<double> variables) {
    return 15 * variables[0] + 16 * variables[1];
}

int main() {


    BisectionMethodImpl bs;
    IterationMethod iterationMethod;
    SecantMethod sm;
    std::cout.precision(20);
    std::cout << "Do you want to solve equation or system? Type 1 if system, else 2" << std::endl;
    int type;
    std::cin >> type;
    if (type == 2) {
        std::cout
                << "what equition you want to solve: polynomial, logarithmic, or trigonometrical? type number"
                << std::endl;
        int num;
        std::cin >> num;
        if (num == 1) {
            auto res = bs.get_root(polynomyal, -20, 20);
            if (!res.success) {
                std::cout << "no roots" << std::endl;
            } else {
                double ans1 = bs.get_root(polynomyal, -20, 20).ans;
                double ans2 = sm.get_root(polynomyal, -20, 20).ans;
                std::cout << "Bisectional: " << ans1 << std::endl;
                std::cout << "Secant: " << ans2 << std::endl;
                std::cout << "Difference: " << std::abs(ans2 - ans1);
            }
        }
            if (num == 2) {
                auto res = bs.get_root(log_func, 0.1, 20);
                if (!res.success) {
                    std::cout << "no roots" << std::endl;
                } else {
                    double ans1 = bs.get_root(log_func, 0.1, 20).ans;
                    double ans2 = sm.get_root(log_func, 0.1, 20).ans;
                    std::cout << "Bisectional: " << ans1 << std::endl;
                    std::cout << "Secant: " << ans2 << std::endl;
                    std::cout << "Difference: " << std::abs(ans2 - ans1);
                }
            }
            if (num == 3) {
                auto res = bs.get_root(trigonometrical_func, -20, 20);
                if (!res.success) {
                    std::cout << "no roots" << std::endl;
                } else {
                    double ans1 = bs.get_root(trigonometrical_func, -20, 20).ans;
                    double ans2 = sm.get_root(trigonometrical_func, -20, 20).ans;
                    std::cout << "Bisectional: " << ans1 << std::endl;
                    std::cout << "Secant: " << ans2 << std::endl;
                    std::cout << "Difference: " << std::abs(ans2 - ans1);
                }
            }
        } else {
            auto system = std::vector<std::function<double(std::vector<double>)>>{func1_system, func2_system,
                                                                                  func3_system};
            auto ans = iterationMethod.solve_system(system, 0.000001);
            for (int i = 0; i < ans.size(); i++) {
                std::cout << "variable" << i + 1 << ": " << ans[i] << std::endl;
            }
        }


    }
