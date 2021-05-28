#include "Transformation.h"

Transformation::Transformation(std::initializer_list<double> items)
{
    int i = 0;

    for (auto &it : items)
    {
        matrix[i++] = it;

        if (i >= MATRIX_SIZE * MATRIX_SIZE)
        {
            break;
        }
    }
}

Transformation::Transformation(const std::vector<std::vector<double>> &data)
{
    for (int y = 0; y < MATRIX_SIZE; y++)
        for (int x = 0; x < MATRIX_SIZE; x++)
            matrix[x + y * MATRIX_SIZE] = data[y][x];
}

Point Transformation::transform(const Point &p) const
{

#define M(i) matrix[i] * p.getX() + matrix[i + 1] * p.getY() + matrix[i + 2] * p.getZ() + matrix[i + 3]

    return Point(
        M(0),
        M(4),
        M(8));
};
