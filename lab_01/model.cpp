#include "model.hpp"
#include <stdlib.h>

static model_t *create_model(void)
{
    model_t *model = (model_t *) malloc(sizeof(model_t));

    if (model == NULL)
    {
        return NULL;
    }

    init_vectors_array(model->vertecies);
    init_lines_array(model->lines);

    return model;
}

static err_t read_model(model_t *&model, FILE *f)
{
    model = create_model();

    if (model == NULL)
    {
        return ALLOC_ERR;
    }

    err_t rc = load_vectors(model->vertecies, f);

    if (rc != OK)
    {
        free_model(model);
        return rc;
    }

    if ((rc = load_lines(model->lines, f)) != OK)
    {
        free_model(model);
        return rc;
    }

    return rc;
}

err_t load_model(model_t *&model, const char *name)
{
    FILE *f = fopen(name, "r");

    if (f == NULL)
    {
        return FILE_ERR;
    }

    model_t *temp = NULL;
    err_t rc = read_model(temp, f);

    fclose(f);

    if (rc == OK)
    {
        free_model(model);
        model = temp;
    }

    return rc;
}

static void draw_line(const drawer_t &drawer, const line_t &link, const vector_t *const vertecies)
{
    vector_t pt1 = vertecies[link.p1];
    vector_t pt2 = vertecies[link.p2];

    drawer.draw_line(
                drawer.data,
                pt1,
                pt2
                );
}

static void draw_links(const drawer_t &drawer, const larray_t &lines, const varray_t &vertecies)
{
    for (int i = 0; i < lines.size; i++)
    {
        draw_line(drawer, lines.array[i], vertecies.array);
    }
}

err_t draw_model(model_t *&model, const drawer_t &drawer)
{
    if (model == NULL)
    {
        return NO_MODEL;
    }

    draw_links(drawer, model->lines, model->vertecies);

    return OK;
}

static void move_vertecies(varray_t &vertecies, const vector_t &coeffs)
{
    for (int i = 0; i < vertecies.size; i++)
    {
        move_vector(vertecies.array[i], coeffs);
    }
}

err_t move_model(model_t *&model, const vector_t &coeffs)
{
    if (model == NULL)
    {
        return NO_MODEL;
    }

    move_vertecies(model->vertecies, coeffs);

    return OK;
}

static void scale_vertecies(varray_t &vertecies, const vector_t &coeffs)
{
    for (int i = 0; i < vertecies.size; i++)
    {
        scale_vector(vertecies.array[i], coeffs);
    }
}

err_t scale_model(model_t *&model, const vector_t &coeffs)
{
    if (model == NULL)
    {
        return NO_MODEL;
    }

    scale_vertecies(model->vertecies, coeffs);

    return OK;
}

static void turn_vertecies(varray_t &vertecies, const vector_t &coeffs)
{
    for (int i = 0; i < vertecies.size; i++)
    {
        turnx_vector(vertecies.array[i], coeffs.x);
        turny_vector(vertecies.array[i], coeffs.y);
        turnz_vector(vertecies.array[i], coeffs.z);
    }
}

err_t turn_model(model_t *&model, const vector_t &coeffs)
{
    if (model == NULL)
    {
        return NO_MODEL;
    }

    turn_vertecies(model->vertecies, coeffs);

    return OK;
}

void free_model(model_t *&model)
{
    if (model == NULL)
    {
        return;
    }

    free_vectors(model->vertecies);
    free_lines(model->lines);
    free(model);

    model = NULL;
}
