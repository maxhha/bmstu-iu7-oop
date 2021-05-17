#include <emscripten/bind.h>
#include "Commands/Commands.h"
#include "Engine/WebGLEngine.h"

#include <memory>

using namespace emscripten;

EMSCRIPTEN_BINDINGS(engine)
{
    class_<WebGLEngine>("Engine")
        .smart_ptr_constructor("Engine", &std::make_shared<WebGLEngine, std::string>);

    class_<RenderCommand>("RenderCommand")
        .constructor<std::shared_ptr<WebGLEngine>>()
        .function("execute", &RenderCommand::execute);
}