#pragma once

class Point
{
public:
    using d = double;
    Point(d _x, d _y, d _z) : x(_x), y(_y), z(_z){};

    d getX() { return x; };
    d getY() { return y; };
    d getZ() { return z; };

    ~Point() = default;

private:
    d x;
    d y;
    d z;
};
