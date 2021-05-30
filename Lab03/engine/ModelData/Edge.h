#pragma once

#include <memory>
#include "Point.h"

class Edge
{
public:
    Edge(int p1, int p2) : start(p1), end(p2){};

    int getStartPoint() const { return start; };
    int getEndPoint() const { return end; };

    ~Edge() = default;

private:
    int start;
    int end;
};
