#include "SceneTreeLoader.h"

std::shared_ptr<Object> SceneTreeLoader::load(const std::string &source)
{
    open(source);

    loadObjectInfo();

    while (hasMoreChildren())
        loadChild();

    close();

    return builder.build();
}