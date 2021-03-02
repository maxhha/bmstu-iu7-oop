#include <emscripten/bind.h>
#include "manager.hpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(model_manager)
{
    function("requestModelManager", &request_model_manager);
    enum_<resp_t>("ManagerResponce")
        .value("OK", OK)
        .value("UNKNOWN_COMMAND", UNKNOWN_COMMAND);
}