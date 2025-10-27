#include "layer.h"

#include <stdlib.h>
#include <err.h>

static float *init_bias(size_t entry_size);

static void free_weights(float **weights, size_t entry_size) {
    for (size_t i = 0; i < entry_size; i++) {
            free(weights[i]);
    }
    free(weights);
}

static float **init_weights(size_t entry_size, size_t output_size);

layer *init_layer(size_t entry_size, size_t output_size, layer_type type, activation_type activation) {

    layer *new = calloc(1, sizeof(layer));
    if (!new) {
        warn("calloc layer");
        return NULL;
    }

    new->entry_size = entry_size;
    new->output_size = output_size;
    new->activation = activation;
    new->type = type;

    new->neurons = calloc(entry_size, sizeof(float));
    if (!new->neurons) {
        free(new);
        warn("calloc layer");
        return NULL;
    }

    // TODO: random init
    new->bias = init_bias(entry_size);
    if (!new->bias) {
        free(new->neurons);
        free(new);
        warn("calloc layer");
        return NULL;
    }

    // TODO: Random init (need to think implem to work with)
    new->weights = init_weights(entry_size, output_size);
    if (!new->weights) {
        free(new->bias);
        free(new->neurons);
        free(new);
        warn("calloc layer");
        return NULL;
    }

    return new;
}

void free_layer(layer *to_free) {
    if (!to_free)
        return;

    free(to_free->neurons);
    free(to_free->bias);
    free_weights(to_free->weights, to_free->entry_size);
    free(to_free);
}
