
#include "swarm.h"
#include "boid.h"
#include "vec2f.h"
#include <iostream> //FOR TESTING


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
    for (const auto &b : flock)
    {
        if (b.getIdNumber() != thisBoid.getIdNumber()) // TODO overload comparison operators for Boid class
        {
            offset.add(b.getPosition());
            std::cout << "b.Position: " + b.getPosition().toString() << std::endl; // FOR TESTING
            std::cout << "b.idNum: " + std::to_string(b.getIdNumber()) << std::endl; // FOR TESTING
            std::cout << "thisBoid.Position: " + thisBoid.getPosition().toString() << std::endl; // FOR TESTING
            std::cout << "thisBoid.idNum: " + std::to_string(thisBoid.getIdNumber()) << std::endl; // FOR TESTING
            std::cout << "offset: " + offset.toString() << std::endl << std::endl; // FOR TESTING
        }
    }
    offset.subtract(thisBoidPosition);
    offset.scalarDivide(100);
    thisBoidPosition.add(offset);
    thisBoid.setPosition(thisBoidPosition);
    std::cout << "FINAL OFFSET: " + offset.toString() << std::endl; // FOR TESTING
    std::cout << "FINAL POSITION: " + thisBoid.getPosition().toString() << std::endl; // FOR TESTING
}

void Swarm::separation(Boid &thisBoid)
{
    // ...
}

void Swarm::alignment(Boid &thisBoid)
{
    // ...
}
