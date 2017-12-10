
#include "swarm.h"
#include "boid.h"
#include "vec2f.h"


Swarm::Swarm()
{
    // ...
}

void Swarm::initialise(int MaxFlockSize, bool bRandomPositions)
{
    this->MaxFlockSize = MaxFlockSize;
    Boid b;
    for (int i = 0; i < MaxFlockSize; i++)
    {
        flock.push_back (b);
    }
}

void Swarm::applyBehaviour()
{
    for (int i = 0; i < MaxFlockSize; i++)
    {
        cohesion(flock[i]);
        separation(flock[i]);
        alignment(flock[i]);
    }
}

int Swarm::getCurrentFlockSize() const
{
    return flock.size();
}

int Swarm::getMaxFlockSize() const
{
    return MaxFlockSize;
}

void Swarm::setMaxFlockSize(int NewMaxSize)
{
    MaxFlockSize = NewMaxSize;
}

void Swarm::cohesion(Boid &thisBoid)
{
    vec2f thisBoidPosition = thisBoid.getPosition();
    vec2f offset(0);
    for (auto Boid &b : flock)
    {
        if (b != thisBoid) // TODO overload comparison operators for Boid class
        {
            offset.add(b.getPosition());
        }
    }
    offset.subtract(thisBoidPosition);
    offset.scalarDivide(100);
    thisBoid.setPosition(thisBoidPosition.add(offset));
}

void Swarm::separation(Boid &thisBoid)
{
    // ...
}

void Swarm::alignment(Boid &thisBoid)
{
    // ...
}
