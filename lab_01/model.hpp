#ifndef __MODEL_HPP__
#define __MODEL_HPP__

#include "ui_mainwindow.h"
#include "vectors.hpp"
#include "lines.hpp"
#include "errors.hpp"

struct model_s
{
    varray_t vertecies;
    larray_t lines;
};

using model_t = struct model_s;

using draw_line_fn = void(const void *data, const vector_t &p1, const vector_t &p2);

struct drawer_s
{
    void * data;
    draw_line_fn *draw_line;
};

using drawer_t = struct drawer_s;

err_t load_model(model_t *&model, const char *name);
err_t draw_model(model_t *&model, const drawer_t &drawer);
err_t move_model(model_t *&model, const vector_t &coeffs);
err_t scale_model(model_t *&model, const vector_t &coeffs);
err_t turn_model(model_t *&model, const vector_t &coeffs);
void free_model(model_t *&model);

#endif // __MODEL_HPP__
