#pragma once

#include <vector>
#include <initializer_list>
#include <engine/ModelData/Point.h>
#define MATRIX_SIZE 4

class Transformation
{
public:
    Transformation(){};
    Transformation(std::initializer_list<double> items);
    explicit Transformation(const std::vector<std::vector<double>> &data);

    Point transform(const Point &p) const;

private:
    double matrix[MATRIX_SIZE * MATRIX_SIZE] = {
        1.0,
        0.0,
        0.0,
        0.0,

        0.0,
        1.0,
        0.0,
        0.0,

        0.0,
        0.0,
        1.0,
        0.0,

        0.0,
        0.0,
        0.0,
        1.0,
    };
};