#ifndef DRAW_HPP
#define DRAW_HPP

#include "mainwindow.h"
#include "vectors.hpp"
#include "lines.hpp"

struct drawer_s
{
    QGraphicsScene *scene;
};

using drawer_t = struct drawer_s;

void draw_lines(const drawer_t &drawer, const larray_t &lines, const varray_t &vertecies);

#endif // DRAW_HPP
