#ifndef VECTORS_HPP
#define VECTORS_HPP

#include <stdio.h>

#include "errors.hpp"

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
int vectors_array_size(const varray_t &vectors);
bool is_empty_vectors_array(const varray_t &vectors);
err_t get_vector(vector_t &res, const varray_t &vectors, int index);
err_t read_vector(vector_t &vector, FILE *f);
err_t load_vectors(varray_t &vectors, FILE *f);
err_t validate_vertecies(const varray_t &vertecies);
void move_vector(vector_t &vector, const vector_t &coeffs);
void move_vectors_array(varray_t &vertecies, const vector_t &coeffs);
void scale_vector(vector_t &vector, const vector_t &coeffs);
void scale_vectors_array(varray_t &vertecies, const vector_t &coeffs);
void rotatex_vector(vector_t &vector, const double &angle);
void rotatey_vector(vector_t &vector, const double &angle);
void rotatez_vector(vector_t &vector, const double &angle);
void rotate_vectors_array(varray_t &vertecies, const vector_t &coeffs);
void free_vectors(varray_t &vectors);

#endif // VECTORS_HPP
