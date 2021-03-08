#include "vectors.hpp"

void init_vectors_array(varray_t &vectors)
{
    vectors.array = NULL;
    vectors.size = 0;
}

static err_t read_amount(varray_t &vectors, FILE *f)
{
    if ((fscanf(f, "%d", &vectors.size)) != 1)
    {
        return READ_ERR;
    }

    if (vectors.size < 2)
    {
        return PSIZE_ERR;
    }

    return OK;
}

static err_t read_vectors(vector_t *const array, const int size, FILE *f)
{
    for (int i = 0; i < size; i++)
    {
        if ((fscanf(f, "%lf %lf %lf", &array[i].x, &array[i].y, &array[i].z)) != 3)
        {
            return READ_ERR;
        }
    }

    return OK;
}

static err_t allocate_links(varray_t &vectors)
{
    vector_t *temp_array = (vector_t *)malloc(vectors.size * sizeof(vector_t));

    if (temp_array == NULL)
    {
        return ALLOC_ERR;
    }

    vectors.array = temp_array;

    return OK;
}

void free_vectors(const varray_t &vectors)
{
    if (vectors.array != NULL)
    {
        free(vectors.array);
    }
}

err_t load_vectors(varray_t &vectors, FILE *f)
{
    err_t rc = read_amount(vectors, f);

    if (rc != OK)
    {
        return rc;
    }

    if ((rc = allocate_links(vectors)) != OK)
    {
        return rc;
    }

    if ((rc = read_vectors(vectors.array, vectors.size, f)) != OK)
    {
        free_vectors(vectors);
    }

    return rc;
}

void move_vector(vector_t &vector, const vector_t &coeffs)
{
    vector.x += coeffs.x;
    vector.y += coeffs.y;
    vector.z += coeffs.z;
}

void scale_vector(vector_t &vector, const vector_t &coeffs)
{
    vector.x *= coeffs.x;
    vector.y *= coeffs.y;
    vector.z *= coeffs.z;
}

static inline double to_radians(const double &angle)
{
    return angle * PI / 180;
}

void turnx_vector(vector_t &vector, const double &angle)
{
    double rad = to_radians(angle);
    double c = cos(rad);
    double s = sin(rad);

    double y = vector.y;
    double z = vector.z;

    vector.y = y * c + z * s;
    vector.z = -y * s + z * c;
}

void turny_vector(vector_t &vector, const double &angle)
{
    double rad = to_radians(angle);
    double c = cos(rad);
    double s = sin(rad);

    double x = vector.x;
    double z = vector.z;

    vector.x = x * c + z * s;
    vector.z = -x * s + z * c;
}

void turnz_vector(vector_t &vector, const double &angle)
{
    double rad = to_radians(angle);
    double c = cos(rad);
    double s = sin(rad);

    double x = vector.x;
    double y = vector.z;

    vector.x = x * c + y * s;
    vector.z = -x * s + y * c;
}
