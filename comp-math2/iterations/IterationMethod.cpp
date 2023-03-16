//
// Created by moyak on 16.03.2023.
//

#include "IterationMethod.h"

std::vector<double> IterationMethod::solve_system(std::vector<std::function<double(std::vector<double>)>> system, double precision) {
    std::vector<double> ans = std::vector<double>(system.size());
    std::fill(ans.begin(), ans.end(),1);
    std::vector<double> buf = ans;
    bool need_iter = true;
    while (need_iter) {
        need_iter = false;
        for (int i = 0; i < system.size(); i++) {
            buf[i] = system[i](ans);
            if(std::abs(buf[i] - ans[i]) > precision) need_iter = true;

        }
        ans = buf;
    }
    return ans;
}
