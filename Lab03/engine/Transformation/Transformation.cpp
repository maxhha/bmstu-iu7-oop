#include "Transformation.h"
#include <QDebug>
#define MATRIX_SIZE 4

Transformation::Transformation(std::initializer_list<double> items)
{
    int i = 0;

    for (auto &it : items)
    {
        matrix[i / MATRIX_SIZE][i % MATRIX_SIZE] = it;
        i++;

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
            matrix[y][x] = data[y][x];
}

Point Transformation::transform(const Point &p) const
{

#define M(i) matrix[i][0] * p.getX() + matrix[i][1] * p.getY() + matrix[i][2] * p.getZ() + matrix[i][3]

    return Point(
        M(0),
        M(1),
        M(2));
};
