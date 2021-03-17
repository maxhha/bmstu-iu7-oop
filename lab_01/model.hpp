#ifndef MODEL_HPP
#define MODEL_HPP

#include "vectors.hpp"
#include "lines.hpp"
#include "errors.hpp"
#include "draw.hpp"

struct model_s
{
    varray_t vertecies;
    larray_t lines;
};

using model_t = struct model_s;

model_t empty_model(void);
err_t load_model(model_t &model, const char *name);
err_t draw_model(model_t &model, const drawer_t &drawer);
err_t move_model(model_t &model, const vector_t &coeffs);
err_t scale_model(model_t &model, const vector_t &coeffs);
err_t rotate_model(model_t &model, const vector_t &coeffs);
void free_model(model_t &model);

#endif // MODEL_HPP
