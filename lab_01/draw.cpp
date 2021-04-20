#include "draw.hpp"

static void draw_line_on_scene(const drawer_t &drawer, vector_t &p1, vector_t &p2)
{
    drawer.scene->addLine(
        p1.x,
        p1.y,
        p2.x,
        p2.y
        );
}

static vector_t centered_point(const vector_t &p, const drawer_t &drawer)
{
    double hh = drawer.scene->height() / 2;
    double hw = drawer.scene->width() / 2;

    vector_t centered = {
        .x = p.x + hw,
        .y = p.y + hh,
        .z = p.z,
    };

    return centered;
}

static void draw_line_in_center(const drawer_t &drawer, const vector_t &p1, const vector_t p2)
{
    vector_t centered_p1 = centered_point(p1, drawer);
    vector_t centered_p2 = centered_point(p2, drawer);

    draw_line_on_scene(
        drawer,
        centered_p1,
        centered_p2
    );
}

static err_t draw_line(const model_t &model, const drawer_t &drawer, const line_t &line)
{
    vector_t p1;
    vector_t p2;
    err_t rc = get_vector(p1, model.vertecies, line.p1);

    if (rc != OK)
    {
        return rc;
    }

    if ((rc = get_vector(p2, model.vertecies, line.p2)) != OK)
    {
        return rc;
    }

    move_vector(p1, model.origin);
    move_vector(p2, model.origin);

    draw_line_in_center(drawer, p1, p2);

    return rc;
}

static err_t draw_lines(const model_t &model, const drawer_t &drawer, const larray_t &lines)
{
    err_t rc = OK;

    for (int i = 0; rc == OK && i < lines.size; i++)
    {
        rc = draw_line(model, drawer, lines.array[i]);
    }

    return rc;
}

err_t draw_model(const model_t &model, const drawer_t &drawer)
{
    if (is_empty_model(model))
    {
        return NO_MODEL;
    }

    return draw_lines(model, drawer, model.lines);
}
