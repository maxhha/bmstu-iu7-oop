#pragma once

#include <memory>
#include "Point.h"

class Edge
{
public:
    using PointPtr = std::shared_ptr<Point>;
    Edge(const PointPtr &p1, const PointPtr &p2) : start(p1), end(p2){};

    const PointPtr &getStartPoint() const { return start; };
    const PointPtr &getEndPoint() const { return end; };

    ~Edge() = default;

private:
    PointPtr start;
    PointPtr end;
};
