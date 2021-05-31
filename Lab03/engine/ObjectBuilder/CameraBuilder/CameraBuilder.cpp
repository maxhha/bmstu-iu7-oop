#include "CameraBuilder.h"
#include <engine/Object/Camera.h>

std::shared_ptr<Object> CameraBuilder::build()
{
    return std::make_shared<Camera>(name, transformation);
};