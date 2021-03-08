#ifndef __VECTORS_HPP__
#define __VECTORS_HPP__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "errors.hpp"

#define PI 3.1415

struct vector_s
{
    double x;
    double y;
    double z;
};

using vector_t = struct vector_s;

struct vectors_array_s
{
    int size = 0;
    vector_t *array = NULL;
};

using varray_t = struct vectors_array_s;

void init_vectors_array(varray_t &vectors);
err_t load_vectors(varray_t &vectors, FILE *f);

void move_vector(vector_t &vector, const vector_t &coeffs);

void scale_vector(vector_t &vector, const vector_t &coeffs);

void turnx_vector(vector_t &vector, const double &angle);

void turny_vector(vector_t &vector, const double &angle);

void turnz_vector(vector_t &vector, const double &angle);

void free_vectors(const varray_t &vectors);

#endif // __VECTORS_HPP__
