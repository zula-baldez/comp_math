//
// Created by moyak on 12.03.2023.
//

#ifndef COMP_MATH2_SECANTMETHOD_H
#define COMP_MATH2_SECANTMETHOD_H
#include <functional>
#include "../util/AnsStruct.h"

#include "../CompMethodAbstr.h"
class SecantMethod : public CompMethodAbstr  {
public:
    Ans get_root(const std::function<double(double)>& func, double left, double right) override;
};


#endif //COMP_MATH2_SECANTMETHOD_H
