#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

#include "vectors.hpp"

void init_vectors_array(varray_t &vectors)
{
    vectors.array = NULL;
    vectors.size = 0;
}

err_t get_vector(vector_t &res, const varray_t &vectors, int index)
{
    if (index < 0 || index >= vectors.size)
    {
        return READ_ERR;
    }

    res = vectors.array[index];

    return OK;
}

bool is_empty_vectors_array(const varray_t &vectors)
{
    return vectors.size == 0;
}

int vectors_array_size(const varray_t &vectors)
{
    return vectors.size;
}

static err_t read_amount(int &size, FILE *f)
{
    int x;

    if ((fscanf(f, "%d", &x)) != 1)
    {
        return READ_ERR;
    }

    if (x < 1)
    {
        return NONPOS_ERR;
    }

    size = x;

    return OK;
}

err_t read_vector(vector_t &vec, FILE *f)
{
    if ((fscanf(f, "%lf %lf %lf", &vec.x, &vec.y, &vec.z)) != 3)
    {
        return READ_ERR;
    }
    return OK;
}

static err_t read_vectors(vector_t *const array, const int size, FILE *f)
{
    err_t rc = OK;

    for (int i = 0; rc == OK && i < size; i++)
    {
        rc = read_vector(array[i], f);
    }

    return rc;
}

static err_t allocate_vectors(varray_t &vectors)
{
    vector_t *temp_array = (vector_t *)malloc(vectors.size * sizeof(vector_t));

    if (temp_array == NULL)
    {
        return ALLOC_ERR;
    }

    vectors.array = temp_array;

    return OK;
}

void free_vectors(varray_t &vectors)
{
    if (vectors.array != NULL)
    {
        free(vectors.array);
        vectors.array = NULL;
    }

    vectors.size = 0;
}

err_t load_vectors(varray_t &vectors, FILE *f)
{
    err_t rc = read_amount(vectors.size, f);

    if (rc != OK)
    {
        return rc;
    }

    if ((rc = allocate_vectors(vectors)) != OK)
    {
        return rc;
    }

    if ((rc = read_vectors(vectors.array, vectors.size, f)) != OK)
    {
        free_vectors(vectors);
    }

    return rc;
}

err_t validate_vertecies(const varray_t &vertecies)
{
    return vertecies.size < 2 ? VERTECIESN_ERR : OK;
}

void move_vector(vector_t &vector, const vector_t &coeffs)
{
    vector.x += coeffs.x;
    vector.y += coeffs.y;
    vector.z += coeffs.z;
}

void move_vectors_array(varray_t &vertecies, const vector_t &coeffs)
{
    for (int i = 0; i < vertecies.size; i++)
    {
        move_vector(vertecies.array[i], coeffs);
    }
}

void scale_vector(vector_t &vector, const vector_t &coeffs)
{
    vector.x *= coeffs.x;
    vector.y *= coeffs.y;
    vector.z *= coeffs.z;
}

void scale_vectors_array(varray_t &vertecies, const vector_t &coeffs)
{
    for (int i = 0; i < vertecies.size; i++)
    {
        scale_vector(vertecies.array[i], coeffs);
    }
}

static inline double to_radians(const double &angle)
{
    return angle * M_PI / 180;
}

void rotatex_vector(vector_t &vector, const double &angle)
{
    double rad = to_radians(angle);
    double c = cos(rad);
    double s = sin(rad);

    double y = vector.y;
    double z = vector.z;

    vector.y = y * c + z * s;
    vector.z = -y * s + z * c;
}

void rotatey_vector(vector_t &vector, const double &angle)
{
    double rad = to_radians(angle);
    double c = cos(rad);
    double s = sin(rad);

    double x = vector.x;
    double z = vector.z;

    vector.x = x * c + z * s;
    vector.z = -x * s + z * c;
}

void rotatez_vector(vector_t &vector, const double &angle)
{
    double rad = to_radians(angle);
    double c = cos(rad);
    double s = sin(rad);

    double x = vector.x;
    double y = vector.y;

    vector.x = x * c + y * s;
    vector.y = -x * s + y * c;
}

void rotate_vectors_array(varray_t &vertecies, const vector_t &coeffs)
{
    for (int i = 0; i < vertecies.size; i++)
    {
        rotatex_vector(vertecies.array[i], coeffs.x);
        rotatey_vector(vertecies.array[i], coeffs.y);
        rotatez_vector(vertecies.array[i], coeffs.z);
    }
}
