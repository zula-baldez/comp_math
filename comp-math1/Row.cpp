//
// Created by moyak on 17.02.2023.
//

#include <stdexcept>
#include "Row.h"
//decreases index automatically
double Row::operator[](int index) const {
    if(index < 0 || index >= get_size()) {
        throw std::runtime_error("wrong index in Row!");
    } else {
        return raw_data[index];
    }
}

Row Row::operator*(double num) {
    Row raw;
    for(double i : raw_data) {
        raw.add(num*i);
    }
    return raw;
}

Row Row::operator+(const Row& raw) const {
    Row raw_new;
    for(int i = 0; i < get_size(); i++) {
        raw_new.add( raw_data[i] + raw[i]);
    }
    return raw;
}

Row Row::operator-(const Row& raw) const {
    Row raw_new;
    for(int i = 0; i < get_size(); i++) {
        raw_new.add( raw_data[i] - raw[i]);
    }
    return raw_new;
}

Row Row::operator/(double num) {
    Row raw;
    for(double i : raw_data) {
        raw.add(i/num);
    }
    return raw;
}


