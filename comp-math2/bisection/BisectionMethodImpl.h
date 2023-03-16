//
// Created by moyak on 12.03.2023.
//

#ifndef COMP_MATH2_BISECTIONMETHODIMPL_H
#define COMP_MATH2_BISECTIONMETHODIMPL_H
#include <functional>
#include "../util/AnsStruct.h"

#include "../CompMethodAbstr.h"
class BisectionMethodImpl : public CompMethodAbstr  {
public:
    Ans get_root(const std::function<double(double)>& func, double left, double right) override;
};


#endif //COMP_MATH2_BISECTIONMETHODIMPL_H
