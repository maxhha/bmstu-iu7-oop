#include "ModelBuilder.h"
#include <engine/Object/Model.h>

std::shared_ptr<Object> ModelBuilder::build()
{
    return std::make_shared<Model>(
        name,
        modelData);
};
