#include "Transformation.h"
#include <QDebug>
#include <math.h>
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

#undef M
};

void Transformation::rotate(double x, double y, double z, double angle)
{
    Transformation m;
    double c = cos(angle);
    double s = sin(angle);
    m.matrix[0][0] = c + (1 - c) * x * x;
    m.matrix[0][1] = (1 - c) * x * y - s * z;
    m.matrix[0][2] = (1 - c) * x * z + s * y;

    m.matrix[1][0] = (1 - c) * x * y + s * z;
    m.matrix[1][1] = c + (1 - c) * y * y;
    m.matrix[1][2] = (1 - c) * y * z - s * x;

    m.matrix[2][0] = (1 - c) * x * z - s * y;
    m.matrix[2][1] = (1 - c) * y * z + s * x;
    m.matrix[2][2] = c + (1 - c) * z * z;

    compose(m);
}

void Transformation::scale(double x, double y, double z)
{
    Transformation m;
    m.matrix[0][0] = x;
    m.matrix[1][1] = y;
    m.matrix[2][2] = z;

    compose(m);
}

void Transformation::translate(double x, double y, double z)
{
    Transformation m;
    m.matrix[0][3] = x;
    m.matrix[1][3] = y;
    m.matrix[2][3] = z;

    compose(m);
}

void Transformation::compose(const Transformation &other)
{
    std::vector<std::vector<double>> m;

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        m.emplace_back();
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            m.back().push_back(0);
        }
    }

    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            for (int k = 0; k < MATRIX_SIZE; k++)
                m[i][j] += matrix[i][k] * other.matrix[k][j];

    matrix = m;
}
