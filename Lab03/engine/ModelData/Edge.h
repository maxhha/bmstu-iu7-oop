#pragma once

#include <memory>
#include "Point.h"

class Edge
{
public:
    using PointPtr = std::shared_ptr<Point>;
    Edge(const PointPtr &p1, const PointPtr &p2) : start(p1), end(p2){};

    PointPtr getStartPoint() { return start; };
    PointPtr getEndPoint() { return end; };

private:
    PointPtr start;
    PointPtr end;
};
