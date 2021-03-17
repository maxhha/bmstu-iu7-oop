#ifndef MODEL_MANAGER_HPP
#define MODEL_MANAGER_HPP

#include "model.hpp"

enum request_type
{
    LOAD,
    SCALE,
    ROTATE,
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

#endif // MODEL_MANAGER_HPP
