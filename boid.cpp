#pragma once

#include "Vec2f.h"
#include <SFML/Graphics.hpp>


/// Constructors

Boid::Boid()
{
	Position.x = 0; Position.y = 0;
}

Boid::Boid(vec2f InitialPosition)
{
	Position.set(InitialPosition);
}

Boid::Boid(float PositionX, PositionY)
{
	Position.set(PositionX, PositionY);
}


/// Getters

vec2f Boid::getPosition() const
{
	return Position;
}

vec2f Boid::getVelocity() const
{
	return Velocity;
}

vec2f Boid::getAcceleration() const
{
	return Acceleration;
}

float Boid::getMaxSpeed() const
{
	return MaxSpeed;
}

float Boid::getMaxForce() const
{
	return MaxForce;
}

sf::Sprite Boid::getSprite() const
{
	return &Sprite;
}


/// Setters
void Boid::setPosition(vec2f NewPosition)
{
	Position.set(NewPosition);
}

void Boid::setVelocity(vec2f NewVelocity)
{
	Velocity.set(NewVelocity);
}

void Boid::setAcceleration(vec2f NewAcceleration)
{
	Acceleration.set(NewAcceleration);
}

void Boid::setMaxSpeed(float NewMaxSpeed)
{
	MaxSpeed = NewMaxSpeed;
}

void Boid::setMaxForce(float NewMaxForce)
{
	MaxForce = NewMaxForce;
}

void Boid::setSpriteTexture(sf::Texture& SpriteTexture)
{
	Sprite.setTexture(SpriteTexture);
}

void Boid::setSpritePosition(vec2f NewPosition)
{
	Sprite.setPosition(NewPosition.x, NewPosition.y);
}

void Boid::applyForce(vec2f ForceToApply)
{
	Acceleration.add(ForceToApply);
}

void Boid::update(float DeltaTime)
{
	// ...
}
