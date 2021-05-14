#include <emscripten/bind.h>
#include "manager.h"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(model_manager)
{
    class_<Engine>("Engine")
        .constructor<std::string>()
        .function("render", &Engine::render);
}