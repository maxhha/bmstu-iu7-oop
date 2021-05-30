#pragma once

#include <vector>
#include <memory>
#include "Edge.h"
class ModelData
{
public:
    void addPoint(double x, double y, double z) { points.emplace_back(x, y, z); };
    void addEdge(int p1, int p2) { edges.emplace_back(p1, p2); };
    const std::vector<Edge> &getEdges() { return edges; };
    const std::vector<Point> &getPoints() { return points; };

    ~ModelData() = default;

private:
    std::vector<Point> points;
    std::vector<Edge> edges;
};