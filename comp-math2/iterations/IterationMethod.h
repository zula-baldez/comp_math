//
// Created by moyak on 16.03.2023.
//

#ifndef COMP_MATH2_ITERATIONMETHOD_H
#define COMP_MATH2_ITERATIONMETHOD_H

#include <iostream>
#include <vector>
#include <functional>

class IterationMethod {
public:
    std::vector<double> solve_system(std::vector<std::function<double(std::vector<double>)>>, double precision   );
};


#endif //COMP_MATH2_ITERATIONMETHOD_H
