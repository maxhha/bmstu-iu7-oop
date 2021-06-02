#include "ModelData.h"

void ModelData::transform(const Transformation &t)
{
    for (auto &point : points)
    {
        point = t.transform(point);
    }
}