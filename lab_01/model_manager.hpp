#ifndef __MODEL_MANAGER_HPP__
#define __MODEL_MANAGER_HPP__

#include "model.hpp"

enum request_type
{
    LOAD,
    SCALE,
    TURN,
    MOVE,
    DRAW,
    QUIT
};

struct request_s
{
    request_type type;
    union
    {
        const char *file_name;
        vector_t coeffs;
        drawer_t drawer;
    };
};

using request_t = struct request_s;

err_t request_model_manager(const request_t &request);

#endif // __MODEL_MANAGER_HPP__
