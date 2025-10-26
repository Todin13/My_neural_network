#ifndef ACTIVATION_H
#define ACTIVATION_H

typedef enum activation_type {
    NONE,
    SIGMOID,
} activation_type;

int (*activation)(float **, float **, float **);

#endif /* ! ACTIVATION_H */
