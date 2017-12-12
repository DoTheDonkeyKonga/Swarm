
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
    for (int i = 0; i < MaxFlockSize; i++)
    {
        Boid b;
        b.setPosition((float)i, (float)i); // FOR TESTING
        b.setIdNumber(i);
        flock.push_back (b);
    }
}

void Swarm::applyBehaviour()
{
    int i = 0;
    vec2f rule1(0), rule2(0), rule3(0);
    for (auto &b : flock)
    {
        rule1 = cohesion(flock[i]);
        rule2 = separation(flock[i]);
        rule3 = alignment(flock[i]);

        vec2f bVelocity = b.getVelocity();
        vec2f bPosition = b.getPosition();
        bVelocity.add(rule1); bVelocity.add(rule2); bVelocity.add(rule3);
        bPosition.add(bVelocity);
        b.setPosition(bPosition);
        i++;
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

/// Rule 1: Cohesion: Boids try to fly towards the centre of mass of neighbouring boids
vec2f Swarm::cohesion(Boid &thisBoid)
{
    vec2f thisBoidPosition = thisBoid.getPosition();
    vec2f offset(0);
    for (const auto &b : flock)
    {
        if (b.getIdNumber() != thisBoid.getIdNumber()) // TODO overload comparison operators for Boid class
        {
            offset.add(b.getPosition());
        }
    }
    offset.subtract(thisBoidPosition);
    offset.scalarDivide(100);
    return offset;
}

/// Rule 2: Separation: Boids try to keep a small distance away from other objects (including other boids)
vec2f Swarm::separation(Boid &thisBoid)
{
    const float DesiredSeparation = 100.0f;
    vec2f temp(0);
    vec2f delta(0);
    for (const auto &b : flock)
    {
        if (b.getIdNumber() != thisBoid.getIdNumber())
        {
            temp.add(b.getPosition());
            temp.subtract(thisBoid.getPosition());
            if (temp.getMagnitude() < DesiredSeparation)
            {
                delta.add(temp);
            }
            // reset temp to zero for next run of loop
            temp.zero();
        }
    }
    return delta;
}

vec2f Swarm::alignment(Boid &thisBoid)
{
    // ...
    return vec2f(0);
}
