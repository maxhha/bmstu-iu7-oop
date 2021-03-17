#ifndef LINES_HPP
#define LINES_HPP

#include <stdio.h>
#include <stdlib.h>

#include "errors.hpp"

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
bool is_empty_lines_array(const larray_t &lines);
err_t load_lines(larray_t &lines, FILE *f);
err_t validate_lines(const larray_t &lines, const int vertecies_n);
void free_lines(larray_t &links);

#endif // LINES_HPP
