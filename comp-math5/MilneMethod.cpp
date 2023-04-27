//
// Created by egor on 27.04.23.
//

#include "MilneMethod.h"

std::pair<std::vector<double>, std::vector<double>> MilneMethod::solveByMilne(std::function<double(double, double)> &f, double epsilon, double a, double y_a, double b) {
    double h = (b - a) / 10;
    while (true) {
        std::vector<double> y(4);
        std::vector<double> x_vec;

        double k1, k2, k3, k4;

        y[0] = y_a;
        k1 = f(a, y[0]);
        k2 = f(a + h / 2, y[0] + h / 2 * k1);
        k3 = f(a + h / 2, y[0] + h / 2 * k2);
        k4 = f(a + h, y[0] + h * k3);
        y[1] = y[0] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);

        k1 = f(a, y[0]);
        k2 = f(a + h / 2, y[1]);
        k3 = f(a + h / 2, y[1]);
        k4 = f(a + h, y[1]);
        y[2] = y[0] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);

        k1 = f(a, y[1]);
        k2 = f(a + h / 2, y[2]);
        k3 = f(a + h / 2, y[2]);
        k4 = f(a + h, y[2]);
        y[3] = y[1] + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);

        x_vec.push_back(a);
        x_vec.push_back(a + h);
        x_vec.push_back(a + 2 * h);
        x_vec.push_back(a + 3 * h);


        int iter = 4;
        double x = a + iter * h;
        bool success = true;
        while (x <= b) {
            x_vec.push_back(x);
            double y_i_1 = y[iter - 4] + 4 * h / 3 * (2 * f(x - 3 * h, y[iter - 3]) -
                                                      f(x - 2 * h, y[iter - 2]) +
                                                      2 * f(x - h, y[iter - 1]));
            y.push_back(y_i_1);
            double y_i_2 =
                    y[iter - 2] + h / 3 * (f(x, y[iter]) + 4 * f(x - h, y[iter - 1]) +
                                           f(x - 2 * h, y[iter - 2]));

            double epsilon_m = std::abs(y_i_1 - y_i_2) / 29;
            if (epsilon_m > epsilon) {
                success = false;
                h /= 10;
                break;
            }
            x += h;
            iter++;
        }
        if (success) {
            return {x_vec, y};
        }
    }
}
