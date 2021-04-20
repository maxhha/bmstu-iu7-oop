#include "lines.hpp"

void init_lines_array(larray_t &lines)
{
    lines.array = NULL;
    lines.size = 0;
}

bool is_empty_lines_array(const larray_t &lines)
{
    return lines.size == 0;
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

static err_t read_line(line_t &line, FILE *f)
{
    if ((fscanf(f, "%d %d", &line.p1, &line.p2)) != 2)
    {
        return READ_ERR;
    }

    return OK;
}

static err_t read_lines(line_t *const array, const int &size, FILE *f)
{
    err_t rc = OK;

    for (int i = 0; rc == OK && i < size; i++)
    {
        rc = read_line(array[i], f);
    }

    return OK;
}

static err_t allocate_lines(larray_t &lines)
{
    line_t *temp_array = (line_t *)malloc(lines.size * sizeof(line_t));

    if (temp_array == NULL)
    {
        return ALLOC_ERR;
    }

    lines.array = temp_array;

    return OK;
}

void free_lines(larray_t &lines)
{
    if (lines.array != NULL)
    {
        free(lines.array);
        lines.array = NULL;
    }

    lines.size = 0;
}

err_t load_lines(larray_t &lines, FILE *f)
{
     err_t rc = read_amount(lines.size, f);

     if (rc != OK)
     {
         return rc;
     }

     if ((rc = allocate_lines(lines)) != OK)
     {
         return rc;
     }

     if ((rc = read_lines(lines.array, lines.size, f)) != OK)
     {
         free_lines(lines);
     }

     return rc;
}

static err_t validate_line(const line_t &line, const int vertecies_n)
{
    if (line.p1 < 0 || line.p1 >= vertecies_n)
        return LINEPTS_ERR;

    if (line.p2 < 0 || line.p2 >= vertecies_n)
        return LINEPTS_ERR;

    return OK;
}

err_t validate_lines(const larray_t &lines, const int vertecies_n)
{
    err_t rc = OK;

    for (int i = 0; rc == OK && i < lines.size; i++)
    {
        rc = validate_line(lines.array[i], vertecies_n);
    }

    return rc;
}
