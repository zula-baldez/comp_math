//
// Created by moyak on 12.03.2023.
//

#ifndef COMP_MATH2_COMPMETHODABSTR_H
#define COMP_MATH2_COMPMETHODABSTR_H
#include "util/AnsStruct.h"
#include <functional>
class CompMethodAbstr {
public:
    virtual Ans get_root(const std::function<double(double)>& func, double left, double right) = 0;
};


#endif //COMP_MATH2_COMPMETHODABSTR_H
