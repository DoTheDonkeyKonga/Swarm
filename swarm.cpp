#pragma once

#include "swarm.h"
#include "boid.h"
#include "vec2f.h"


Swarm::Swarm(int MaxFlockSize)
{
    MaxSize = MaxFlockSize;
}

Swarm::initialise(int MaxFlockSize, bool bRandomPositions = false)
{
    Boid b;
    for (int i = 0; i < MaxSize; i++)
    {
        flock.push_back (b);
    }
}

void Swarm::applyBehaviour()
{
    for (int i = 0; i < MaxSize; i++)
    {
        cohesion(flock[i]);
        separation(flock[i]);
        alignment(flock[i]);
    }
}

void Swarm::getMaxSize() const
{
    return MaxSize;
}

void Swarm::setMaxSize(int NewMaxSize)
{
    MaxSize = NewMaxSize;
}

void Swarm::cohesion(Boid &thisBoid)
{
    vec2f offset(0);
    // For all other Boids in the flock
    for (auto b : flock)
    {
        if (b != thisBoid)
        {
            offset = offset.add(b.getPosition());
        }
    }
    offset.subtract(thisBoid.Position);
    offset.scalarDivide(100);
    thisBoid.setPosition(thisBoid.getPosition().add(offset));
}

void Swarm::separation(Boid &thisBoid)
{
    // ...
}

void Swarm::alignment(Boid &thisBoid)
{
    // ...
}
