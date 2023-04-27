#include <bits/stdc++.h>
#include "matplotlib.h"
#include "MilneMethod.h"
using namespace std;

namespace plt = matplotlibcpp;


double first_function(double x, double y) {
    return sin(x);
}

double second_function(double x, double y) {
    return (x * y) / 2;
}


double third_function(double x, double y) {
    return x + y;
}

double default_function(double x, double y) {
    return 0.0;
}


int main() {
    function<double(double, double)> f1 = first_function;
    function<double(double, double)> f2 = second_function;
    function<double(double, double)> f3 = third_function;
    function<double(double, double)> f4 = default_function;

    MilneMethod mm;
    cout<<"if you want to solve y` = sin(x) type 1"<<endl;

    cout<<"if you want to solve y` = xy/2 type 2"<<endl;

    cout<<"if you want to solve y` = x + y type 3"<<endl;

    cout<<"if you want to solve y` = 0 type 4"<<endl;
    int type;
    cin>>type;
    double eps;
    cout<<"enter accuracy"<<endl;
    cin>>eps;
    cout<<"enter left and right border"<<endl;
    double l, r;
    cin>>l>>r;
    cout<<"enter initial condition"<<endl;
    double y_0;
    cin>>y_0;
    pair<vector<double>, vector<double>> i;
    vector<double> x_an;
    vector<double> y_an;

    if(type==1) {
        i=mm.solveByMilne(f1, eps, l, y_0, r);
        double h = (r - l)/10000;
        double x = l;
        double C = y_0 + cos(l);
        //C - cos(x) = F(X)
        while(x < r) {
            x_an.push_back(x);
            y_an.push_back(C - cos(x));
            x+=h;
        }
    }
    if(type==2) {
        i=mm.solveByMilne(f2, eps, l, y_0, r);
        double h = (r - l)/10000;
        double x = l;
        double C = y_0 / (exp(l*l/4));
        //F(x) = C * e * (x^2/4)
        while(x < r) {
            x_an.push_back(x);
            y_an.push_back(C * exp(x*x/4));
            x+=h;
        }


    }
    if(type==3) {
        i=mm.solveByMilne(f3, eps, l, y_0, r);
        double h = (r - l)/10000;
        double x = l;
        double C = (y_0 + l + 1)/ exp(l);
        //F(x) = C*e^x - x - 1
        while(x < r) {
            x_an.push_back(x);
            y_an.push_back(C*exp(x)-x-1);
            x+=h;
        }
    }
    if(type==4) {
        i=mm.solveByMilne(f4, eps, l, y_0, r);
        double h = (r - l)/10000;
        double x = l;
        double C = y_0;
        //F(x) = C*e^x - x - 1
        while(x < r) {
            x_an.push_back(x);
            y_an.push_back(y_0);
            x+=h;
        }

    }
    plt::plot(i.first, i.second);
    plt::plot(x_an, y_an);
    plt::xlabel("x");
    plt::ylabel("y");
    plt::show();


}
