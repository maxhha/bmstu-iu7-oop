#include "lines.hpp"

void init_lines_array(larray_t &lines)
{
    lines.array = NULL;
    lines.size = 0;
}

static err_t read_amount(larray_t &lines, FILE *f)
{
    if ((fscanf(f, "%d", &lines.size)) != 1)
    {
        return READ_ERR;
    }

    if (lines.size < 1)
    {
        return LSIZE_ERR;
    }

    return OK;
}

static err_t read_lines(line_t *const array, const int &size, FILE *f)
{
    for (int i = 0; i < size; i++)
    {
        if ((fscanf(f, "%d %d", &array[i].p1, &array[i].p2)) != 2)
        {
            return READ_ERR;
        }
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

void free_lines(const larray_t &lines)
{
    if (lines.array != NULL)
    {
        free(lines.array);
    }
}

err_t load_lines(larray_t &lines, FILE *f)
{
     err_t rc = read_amount(lines, f);

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
