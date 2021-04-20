#ifndef DRAW_HPP
#define DRAW_HPP

#include "ui_mainwindow.h"
#include "model.hpp"

struct drawer_s
{
    QGraphicsScene *scene;
};

using drawer_t = struct drawer_s;

err_t draw_model(const model_t &model, const drawer_t &drawer);

#endif // DRAW_HPP
