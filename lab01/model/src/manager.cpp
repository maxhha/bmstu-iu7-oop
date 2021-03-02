#include "manager.hpp"

resp_t request_model_manager(request_t req)
{
    switch (req.type)
    {
    case LOAD:
        return OK;
    default:
        return UNKNOWN_COMMAND;
    }
}