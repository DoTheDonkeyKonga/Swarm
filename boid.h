#ifndef BOID_H_DZG_INCLUDED
#define BOID_H_DZG_INCLUDED

#pragma once

#include <SFML/Graphics.hpp>
#include "vec2f.h"


/*
	A class to describe a "Bird-oid" type object capable of
	exhibiting flocking behaviour.

	Writtten by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
	05.12.2017, ver: 1.0
*/


class Boid {

public:
    // Default constructor: places the Boid at location (0, 0)
	Boid();
	// Conversion constructors
	Boid(vec2f InitialPosition);
	Boid(float PositionX, float PositionY);


	bool bPredator;

	vec2f getPosition() const;
	vec2f getVelocity() const;
	vec2f getAcceleration() const;
	float getMaxSpeed() const;
	float getMaxForce() const;
	int getIdNumber() const;
	sf::Sprite getSprite();
	sf::CircleShape getShape();

	void setPosition(vec2f NewPosition);
	void setPosition(float NewX, float NewY);
	void setVelocity(vec2f NewVelocity);
	void setVelocity(float NewX, float NewY);
	void setAcceleration(vec2f NewAcceleration);
	void setAcceleration(float NewX, float NewY);
	void setMaxSpeed(float NewMaxSpeed);
	void setMaxForce(float NewMaxForce);
	void setIdNumber(int NewId);
	void setSpriteTexture(sf::Texture& SpriteTexture);
	void setSpritePosition(vec2f NewPosition);

	void applyForce(vec2f ForceToApply);

	void update(float DeltaTime);

private:

	vec2f Position;
	vec2f Velocity;
	vec2f Acceleration;

	float Size = 5.0f; // Sensible default for testing
	float MaxSpeed;
	float MaxForce;

	int idNum;

	sf::Sprite Sprite;
	sf::CircleShape Shape;
};

#endif // BOID_H_DZG_INCLUDED
