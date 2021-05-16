#include <emscripten/bind.h>
#include "Commands/Commands.h"
#include "Engine/WebGLEngine.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(engine)
{
    class_<WebGLEngine>("Engine")
        .constructor<std::string>()
        .smart_ptr<std::shared_ptr<WebGLEngine>>("Engine");

    class_<RenderCommand>("RenderCommand")
        .constructor<std::shared_ptr<Engine>>();
}