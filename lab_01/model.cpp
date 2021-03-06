#include "model.hpp"
#include <stdlib.h>

model_t empty_model(void)
{
    model_t model;
    init_vectors_array(model.vertecies);
    init_lines_array(model.lines);

    return model;
}

bool is_empty_model(const model_t &model)
{
    return (
        is_empty_vectors_array(model.vertecies) &&
        is_empty_lines_array(model.lines)
    );
}

static void convert_vertecies_err(err_t &rc)
{
    if (rc == NONPOS_ERR)
    {
        rc = VERTECIESN_ERR;
    }
}

static void convert_lines_err(err_t &rc)
{
    if (rc == NONPOS_ERR)
    {
        rc = LINESN_ERR;
    }
}

static err_t read_model(model_t &model, FILE *f)
{
    model = empty_model();

    err_t rc = read_vector(model.origin, f);

    if (rc == OK)
    {
        rc = load_vectors(model.vertecies, f);
        convert_vertecies_err(rc);
    }

    if (rc == OK)
    {
        rc = load_lines(model.lines, f);
        convert_lines_err(rc);

        if (rc != OK)
        {
            free_vectors(model.vertecies);
        }
    }

    return rc;
}

static err_t validate_model(model_t &model)
{
    err_t rc = validate_vertecies(model.vertecies);

    if (rc != OK)
    {
        return rc;
    }

    int vertecies_n = vectors_array_size(model.vertecies);

    if ((rc = validate_lines(model.lines, vertecies_n)) != OK)
    {
        return rc;
    }

    return rc;
}

err_t load_model(model_t &model, const char *name)
{
    FILE *f = fopen(name, "r");

    if (f == NULL)
    {
        return FILE_ERR;
    }

    model_t temp;
    err_t rc = read_model(temp, f);

    fclose(f);

    if (rc == OK && (rc = validate_model(temp)) != OK)
    {
        free_model(temp);
    }

    if (rc == OK)
    {
        free_model(model);
        model = temp;
    }

    return rc;
}

err_t move_model(model_t &model, const vector_t &coeffs)
{
    if (is_empty_model(model))
    {
        return NO_MODEL;
    }

    move_vector(model.origin, coeffs);

    return OK;
}

err_t scale_model(model_t &model, const vector_t &coeffs)
{
    if (is_empty_model(model))
    {
        return NO_MODEL;
    }

    scale_vectors_array(model.vertecies, coeffs);

    return OK;
}

err_t rotate_model(model_t &model, const vector_t &coeffs)
{
    if (is_empty_model(model))
    {
        return NO_MODEL;
    }

    rotate_vectors_array(model.vertecies, coeffs);

    return OK;
}

void free_model(model_t &model)
{
    free_vectors(model.vertecies);
    free_lines(model.lines);
}
