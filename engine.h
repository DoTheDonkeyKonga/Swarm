#ifndef ENGINE_H_DZG_INCLUDED
#define ENGINE_H_DZG_INCLUDED

#pragma once

#include "swarm.h"


/*
    A class to control our game loop.
    Sets up an SFML window, instantiates our Swarm then loops checking for
    input, calling on Swarm to apply the flocking algorithm then rendering
    the drawables to the SFML window until the game is closed.

	Written by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
	07.12.2017, ver: 1.0
*/


class Engine{

public:
    // Default constructor
    Engine();

	void run();
	Swarm swarm;

private:

	sf::RenderWindow Window;

	int WindowWidth;
	int WindowHeight;

	// declare a Sprite and Texture for the background
	sf::Sprite BackgroundSprite;    // TODO add these to Engine's constructor when finished testing
	sf::Texture BackgroundTexture;

    void checkInput();
	void update();
	void render();
};

#endif // ENGINE_H_DZG_INCLUDED
