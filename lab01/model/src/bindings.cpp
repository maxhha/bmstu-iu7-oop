#include <emscripten/bind.h>
#include "manager.hpp"

using namespace emscripten;

EMSCRIPTEN_BINDINGS(model_manager)
{
    function("requestModelManager", &request_model_manager);
    enum_<resp_t>("ManagerResponce")
        .value("OK", OK)
        .value("UNKNOWN_COMMAND", UNKNOWN_COMMAND);
    enum_<request_type_t>("RequestType")
        .value("LOAD", LOAD);
    value_object<request_s>("ManagerRequest")
        .field("type", &request_s::type);
}