#include "ModelLoader.h"

std::shared_ptr<Object> ModelLoader::load(const std::string &source)
{
    open(source);

    loadObjectInfo();
    loadPoints();
    loadEdges();

    close();

    return builder.build();
}