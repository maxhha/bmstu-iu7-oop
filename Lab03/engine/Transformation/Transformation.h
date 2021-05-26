#pragma once

#include <vector>
#define MATRIX_SIZE 4

class Transformation
{
public:
    Transformation() noexcept {};
    explicit Transformation(const std::vector<std::vector<double>> &data);

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