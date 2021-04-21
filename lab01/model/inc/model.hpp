#ifndef __MODEL_HPP__
#define __MODEL_HPP__

#include <stdio.h>
#include "vector.hpp"

typedef struct model_s
{
    vector_t *vertecies;
    int *figures;
    int figures_size;
    int vertecies_size;
} model_t;

// int load_model(model_t &model, FILE *f);

#endif // __MODEL_HPP__
