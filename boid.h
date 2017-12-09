#ifndef BOID_H_DZG_INCLUDED
#define BOID_H_DZG_INCLUDED

#pragma once

#include <SFML/Graphics.hpp>
#include "vec2f.h"


/*
	Writtten by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
	05.12.2017, ver.1.0

	A class to describe a "Bird-oid" type object that exhibits flocking
	behaviour.
*/


// Forward declarations
class vec2f;
class sf::Texture;
class sf::Sprite;
class sf::CircleShape;


class Boid {

public:
    	// Default constructor
	Boid();
	Boid(vec2f InitialPosition);
	Boid(float PositionX, float PositionY);

	bool bPredator;

	vec2f getPosition() const;
	vec2f getVelocity() const;
	vec2f getAcceleration() const;
	float getMaxSpeed() const;
	float getMaxForce() const;
	sf::Sprite getSprite();
	sf::CircleShape getShape();

	void setPosition(vec2f NewPosition);
	void setVelocity(vec2f NewVelocity);
	void setAcceleration(vec2f NewAcceleration);
	void setMaxSpeed(float NewMaxSpeed);
	void setMaxForce(float NewMaxForce);
	void setSpriteTexture(sf::Texture& SpriteTexture);
	void setSpritePosition(vec2f NewPosition);

	void applyForce(vec2f ForceToApply);

	void update(float DeltaTime);

private:

	vec2f Position;
	vec2f Velocity;
	vec2f Acceleration;

	float Size = 3.5f; // Sensible default for testing
	float MaxSpeed;
	float MaxForce;

	// If using SFML
	sf::Sprite Sprite;
	sf::CircleShape Shape;
};

#endif // BOID_H_DZG_INCLUDED
