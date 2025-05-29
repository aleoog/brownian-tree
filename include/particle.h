#ifndef PARTICLE_H
#define PARTICLE_H

#include "main.h"

#define NUM_PARTICLES 10000

typedef struct Partcle
{
    float x;
    float y;
    // bool is_attached;
} Particle;

Particle walk(Particle *particle);
#endif