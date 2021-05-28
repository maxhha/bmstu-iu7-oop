#pragma once

#include <vector>
#include <memory>
#include "Edge.h"
class ModelData
{
public:
    void addPoint(double x, double y, double z) { points.push_back(std::make_shared<Point>(x, y, z)); };
    void addEdge(int p1, int p2) { edges.push_back(Edge(points[p1], points[p2])); };
    const std::vector<Edge> &getEdges() { return edges; };

    ~ModelData() = default;

private:
    std::vector<std::shared_ptr<Point>> points;
    std::vector<Edge> edges;
};