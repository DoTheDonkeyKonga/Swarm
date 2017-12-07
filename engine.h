#ifndef ENGINE_H_DZG_INCLUDED
#define ENGINE_H_DZG_INCLUDED

#pragma once


/*
	Written by DoTheDonkeyKonga @ I_M_Awesome Productions
	IMAProductions@cyber-wizard.com
	07.12.2017, ver.1.0
*/


class Engine{

public:

    Engine();
	void run();


private:
	// an SFML RenderWindow
	sf::RenderWindow Window;

	int WindowWidth;
	int WindowHeight;

	// declare a Sprite and Texture for the background
	sf::Sprite BackgroundSprite;
	sf::Texture BackgroundTexture;

    void input();
	void update(float DTimeAsSeconds);
	void draw();
};

#endif // ENGINE_H_DZG_INCLUDED
