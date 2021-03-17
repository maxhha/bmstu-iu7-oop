#include "model_manager.hpp"

err_t request_model_manager(const request_t &request)
{
    static model_t model = empty_model();
    err_t rc = OK;

    switch (request.type)
    {
        case LOAD:
            rc = load_model(model, request.file_name);
            break;
        case MOVE:
            rc = move_model(model, request.coeffs);
            break;
        case SCALE:
            rc = scale_model(model, request.coeffs);
            break;
        case ROTATE:
            rc = rotate_model(model, request.coeffs);
            break;
        case DRAW:
            rc = draw_model(model, request.drawer);
            break;
        case QUIT:
            free_model(model);
            break;
        default:
            rc = UNKNOWN_COMMAND;
    }

    return rc;
}
