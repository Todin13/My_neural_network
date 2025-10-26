#ifndef LAYER_H
#define LAYER_H

#include "activation.h"

typedef enum layer_type {
    ENTRY,
    HIDDEN,
    OUTPUT,
} layer_type;

typedef struct layer {
    float **neurons;
    float **weights;
    float **bias; // NULL for entry layer
    layer_type type;
    activation_type activation; // NULL for entry layer
} layer;

#endif /* ! LAYER_H */
