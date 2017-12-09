
#include "boid.h"
#include "vec2f.h"
#include <SFML/Graphics.hpp>


Boid::Boid()
{
	Position.x = 0; Position.y = 0;
	Shape.setPosition(Position.x, Position.y);
	Shape.setFillColor(sf::Color::Green);
	Shape.setOutlineColor(sf::Color::White);
	Shape.setOutlineThickness(1);
	Shape.setRadius(Size);
}

Boid::Boid(vec2f InitialPosition)
{
	Position.set(InitialPosition);
    Shape.setPosition(Position.x, Position.y);
	Shape.setFillColor(sf::Color::Green);
	Shape.setOutlineColor(sf::Color::White);
	Shape.setOutlineThickness(1);
	Shape.setRadius(Size);
}

Boid::Boid(float PositionX, float PositionY)
{
	Position.set(PositionX, PositionY);
    Shape.setPosition(Position.x, Position.y);
	Shape.setFillColor(sf::Color::Green);
	Shape.setOutlineColor(sf::Color::White);
	Shape.setOutlineThickness(1);
	Shape.setRadius(Size);
}

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

sf::CircleShape Boid::getShape()
{
    return Shape;
}

sf::Sprite Boid::getSprite()
{
	return Sprite;
}

void Boid::setPosition(vec2f NewPosition)
{
	Position.set(NewPosition);
	Shape.setPosition(NewPosition.x, NewPosition.y);
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
