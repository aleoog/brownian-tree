#ifndef PARTICLE_H
#define PARTICLE_H

#include "main.h"

typedef struct Partcle
{
    float x;
    float y;
    // bool is_attached;
} Particle;

Particle walk(Particle *particle);
#endif