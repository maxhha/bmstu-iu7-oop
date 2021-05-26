#include "Transformation.h"

Transformation::Transformation(const std::vector<std::vector<double>> &data)
{
    for (int y = 0; y < MATRIX_SIZE; y++)
        for (int x = 0; x < MATRIX_SIZE; x++)
            matrix[x + y * MATRIX_SIZE] = data[y][x];
}
