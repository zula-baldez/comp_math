#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#include "matplotlib.h"
#include "NewtonMethod.h"

namespace plt = matplotlibcpp;
double eps = 0.1;

std::vector<double> x_sin;
std::vector<double> y_sin;
int sin_left = -3;
int sin_right = 4;
std::function<double(double)> func_sin = [](double x) { return sin(x); };

std::vector<double> x_polynom;
std::vector<double> y_polynom;
std::function<double(double)> func_polynom = [](double i) { return i * i * i - 3 * i * i + 2 * i - 1; };

int polynom_left = -3;
int polynom_right = 4;

std::vector<double> x_rnd_func;
std::vector<double> y_rnd_func;
int rnd_func_left = -3;
int rnd_func_right = 4;
std::function<double(double)> func_rand = [](double i) { return sin(i) * i + 2 - cos(i); };


std::vector<double> to_interpolate_x;
std::vector<double> to_interpolate_y;


void generate_data_for_function() {
    for (double i = sin_left; i <= sin_right; i += eps) {
        x_sin.push_back(i);
        y_sin.push_back(sin(i));
    }
    for (double i = polynom_left; i <= polynom_right; i += eps) {
        x_polynom.push_back(i);
        y_polynom.push_back(i * i * i - 3 * i * i + 2 * i - 1);
    }
    for (double i = rnd_func_left; i <= rnd_func_right; i += eps) {
        x_rnd_func.push_back(i);
        y_rnd_func.push_back(sin(i) * i + 2 - cos(i));
    }
}

void generate_points_to_interpolate(int left, int right, int points_num, std::function<double(double)> &func) {

    for (double j = left; j <= right; j += (right - left) * 1.0 / points_num) {
        to_interpolate_x.push_back(j + j * (rand() * 1.0 / RAND_MAX * 0.2 - 0.1));

    }
    for (auto &j: to_interpolate_x) {
        double val = func(j);
        to_interpolate_y.push_back(val + val * (rand() * 1.0 /RAND_MAX * 0.2 - 0.1));
    }


}
std::vector<double> interpolated_x;
std::vector<double> interpolated_y;
NewtonMethod nm;

void interpolate(int left, int right, std::function<double(double)>& func) {
    generate_points_to_interpolate(left, right, 10, func);
    auto coef = nm.interpolate_by_newton(to_interpolate_x, to_interpolate_y);
    for(double i = sin_left; i <= sin_right; i += eps) {
        interpolated_x.push_back(i);
        interpolated_y.push_back(nm.calculate_in_point(coef, to_interpolate_x, i));
    }

}

int main() {
    generate_data_for_function();
    std::cout << "if you want to interpolate sin type 1" << std::endl;

    std::cout << "if you want to interpolate polynomial func type 2" << std::endl;

    std::cout << "if you want to interpolate another func type 3" << std::endl;
    int n;
    std::cin >> n;


    if (n == 1) {
        plt::plot(x_sin, y_sin);
        interpolate(sin_left, sin_right, func_sin);
    }
    if (n == 2) {
        plt::plot(x_polynom, y_polynom);
        interpolate(polynom_left, polynom_right, func_polynom);

    }
    if (n == 3) {
        plt::plot(x_rnd_func, y_rnd_func);
        interpolate(rnd_func_left, rnd_func_right, func_rand);

    }

    plt::plot(interpolated_x, interpolated_y);

    plt::show();
}
