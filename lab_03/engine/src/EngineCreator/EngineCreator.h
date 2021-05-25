#pragma once

#include <memory>
#include <string>
#include "Engine/WebGLEngine.h"

class EngineCreator
{
    static std::shared_ptr<Engine> createEngine(std::string name);
};
