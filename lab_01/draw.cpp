#include "draw.hpp"

static void draw_line(QGraphicsScene *scene, const line_t &line, const vector_t *const vertecies)
{
    vector_t p1 = vertecies[line.p1];
    vector_t p2 = vertecies[line.p2];

    double hh = scene->height() / 2;
    double hw = scene->width() / 2;

    scene->addLine(
        p1.x + hw,
        p1.y + hh,
        p2.x + hw,
        p2.y + hh
        );
}

void draw_lines(const drawer_t &drawer, const larray_t &lines, const varray_t &vertecies)
{
    for (int i = 0; i < lines.size; i++)
    {
        draw_line(drawer.scene, lines.array[i], vertecies.array);
    }
}
