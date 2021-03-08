#ifndef __LINES_HPP__
#define __LINES_HPP__

#include <stdio.h>
#include <stdlib.h>

#include "ui_mainwindow.h"
#include "errors.hpp"
#include "vectors.hpp"

struct line_s
{
    int p1;
    int p2;
};

using line_t = struct line_s;

struct lines_array_s
{
    int size = 0;
    line_t *array = NULL;
};

using larray_t = struct lines_array_s;

void init_lines_array(larray_t &lines);
err_t load_lines(larray_t &lines, FILE *f);
void free_lines(const larray_t &links);

#endif // __LINES_HPP__
