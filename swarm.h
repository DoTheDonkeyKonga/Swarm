#ifndef SWARM_H_DZG_INCLUDED
#define SWARM_H_DZG_INCLUDED

#pragma once

#include "boid.h"


/*
	Written by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
	08.12.2017, ver.1.0
*/


// Forward declarations
class vec2f;
class Boid;

class Swarm{

public:

    // Constructor
    Swarm();

    std::vector<Boid> flock;

    void initialise(int MaxFlockSize, bool bRandomPositions = false);
    void applyBehaviour();
    int getMaxFlockSize() const;
    void setMaxFlockSize(int NewMaxSize);

private:

    int MaxFlockSize;

    /// The three main rules of our algorithm:
    // Rule 1: Cohesion: Boids try to fly towards the centre of mass of neighbouring boids
    void cohesion(Boid &thisBoid);
    // Rule 2: Separation: Boids try to keep a small distance away from other objects (including other boids)
    void separation(Boid &thisBoid);
    // Rule 3: Alignment: Boids try to match velocity with nearby boids
    void alignment(Boid &thisBoid);
};


#endif // SWARM_H_DZG_INCLUDED
