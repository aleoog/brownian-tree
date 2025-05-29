#include "particle.h"

Particle walk(Particle *particle)
{
    float dx = (rand() % 3) - 1;
    float dy = (rand() % 3) - 1;

    return (Particle){particle->x + dx, particle->y + dy};
}
