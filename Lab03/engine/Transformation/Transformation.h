#pragma once

#include <vector>
#include <initializer_list>
#include <engine/ModelData/Point.h>

class Transformation
{

public:
    Transformation(){};
    Transformation(std::initializer_list<double> items);
    explicit Transformation(const std::vector<std::vector<double>> &data);

    const std::vector<std::vector<double>> &getMatrix() const { return matrix; };
    Point transform(const Point &p) const;
    void rotate(double x, double y, double z, double angle);
    void scale(double x, double y, double z);
    void translate(double x, double y, double z);
    void compose(const Transformation &other);

private:
    std::vector<std::vector<double>> matrix{
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}};
};