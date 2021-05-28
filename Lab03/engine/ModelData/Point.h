#pragma once

class Point
{
public:
    using d = double;
    Point(d _x, d _y, d _z) : x(_x), y(_y), z(_z){};

    d getX() const { return x; };
    d getY() const { return y; };
    d getZ() const { return z; };

    ~Point() = default;

private:
    d x;
    d y;
    d z;
};
