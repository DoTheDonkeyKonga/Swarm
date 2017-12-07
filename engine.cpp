#pragma once

#include <SFML/Graphics.hpp>
#include "engine.h"


Engine::Engine()
{
    // Construct SFML window
    sf::VideoMode Desktop = sf::VideoMode::getDesktopMode();
    this->WindowWidth = Desktop.width;
    this->WindowHeight = Desktop.height;
    this->Window.create(sf::VideoMode(WindowWidth, WindowHeight, Desktop.bitsPerPixel), "Swarm", sf::Style::Fullscreen);
}

void Engine::run()
{
    while (Window.isOpen())
    {
            input();
            //update();
            //draw();
    }
}

void Engine::input()
{
    sf::Event InputEvent;
    while (Window.pollEvent(InputEvent))
    {
        if (InputEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Window.close();
        }
    }
}

void Engine::update()
{
    // ...
}

void Engine::draw()
{
    // ...
}
