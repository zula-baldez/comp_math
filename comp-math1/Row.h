//
// Created by moyak on 17.02.2023.
//

#ifndef UNTITLED8_ROW_H
#define UNTITLED8_ROW_H

#include <utility>
#include <vector>
#include <iostream>

class Row {
public:
    Row() = default;

    Row(const Row & raw) {
        raw_data.clear();
        for(auto i : raw.get_data()) {
            raw_data.push_back(i);
        }
    }

    explicit Row(std::vector<double> data) {
        raw_data = std::move(data);
    }
    Row operator-(const Row& raw) const;

    Row operator+(const Row& raw) const;

    Row operator*(double num);

    Row operator/(double num);

    Row& operator=(Row const& raw) = default;


    double operator[](int index) const;

    std::size_t get_size() const {
        return raw_data.size();
    }
    void add(double num) {
        raw_data.push_back(num);
    }
    std::vector<double> get_data() const {
        return raw_data;
    }
private:
    std::vector<double> raw_data;
};


#endif //UNTITLED8_ROW_H
