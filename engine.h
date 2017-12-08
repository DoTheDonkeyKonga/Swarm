#ifndef ENGINE_H_DZG_INCLUDED
#define ENGINE_H_DZG_INCLUDED

#pragma once


/*
	Written by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
	07.12.2017, ver.1.0
*/


// Forward declarations
class Swarm;

class Engine{

public:

    Engine();
	void run();
	Swarm swarm(250);


private:
	// an SFML RenderWindow
	sf::RenderWindow Window;

	int WindowWidth;
	int WindowHeight;

	// declare a Sprite and Texture for the background
	sf::Sprite BackgroundSprite;
	sf::Texture BackgroundTexture;

    void checkInput();
	void update(float DTimeAsSeconds);
	void render();
};

#endif // ENGINE_H_DZG_INCLUDED
