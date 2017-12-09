#ifndef ENGINE_H_DZG_INCLUDED
#define ENGINE_H_DZG_INCLUDED

#pragma once

#include "swarm.h"

/*
	Written by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
	07.12.2017, ver.1.0
*/


class Engine{

public:

    Engine();
	void run();
	Swarm swarm;


private:
	// an SFML RenderWindow
	sf::RenderWindow Window;

	int WindowWidth;
	int WindowHeight;

	// declare a Sprite and Texture for the background
	sf::Sprite BackgroundSprite;    // TODO add this to Engine's constructor when finished testing
	sf::Texture BackgroundTexture;

    void checkInput();
	void update();
	void render();
};

#endif // ENGINE_H_DZG_INCLUDED
