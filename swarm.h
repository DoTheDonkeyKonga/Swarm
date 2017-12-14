#ifndef SWARM_H_DZG_INCLUDED
#define SWARM_H_DZG_INCLUDED

#pragma once

#include "boid.h"


/*
    A class to contain a flock of Boids.
    Applies the three main rules of the algorithm; cohesion, separation
    and alignment. Keeps track of and can manipulate the flock size.

	Written by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
	08.12.2017, ver: 1.0
*/


class Swarm{

public:

    // Constructor
    Swarm();

    std::vector<Boid> flock;

    void initialise(int MaxFlockSize, bool bRandomPositions = false);
    void randomisePositions();
    void applyBehaviour();
    void checkBounds();

    int getCurrentFlockSize() const;
    int getMaxFlockSize() const;

    void setMaxFlockSize(int NewMaxSize);

private:

    int MaxFlockSize;

    /// The three main rules of our algorithm:
    // Rule 1: Cohesion: Boids try to fly towards the centre of mass of neighbouring boids
    vec2f cohesion(Boid &thisBoid);
    // Rule 2: Separation: Boids try to keep a small distance away from other objects (including other boids)
    vec2f separation(Boid &thisBoid);
    // Rule 3: Alignment: Boids try to match velocity with nearby boids
    vec2f alignment(Boid &thisBoid);
};


#endif // SWARM_H_DZG_INCLUDED
