
#include <SFML/Graphics.hpp>
#include "swarm.h"
#include "engine.h"


Engine::Engine()
{
    // Construct SFML window
    sf::VideoMode Desktop = sf::VideoMode::getDesktopMode();
    WindowWidth = Desktop.width;
    WindowHeight = Desktop.height;
    Window.create(sf::VideoMode(WindowWidth, WindowHeight, Desktop.bitsPerPixel), "Swarm", sf::Style::Default);
    Window.setFramerateLimit(60); // Optional
}

void Engine::run()
{
    // Initialise our Swarm of Boids
    swarm.initialise(250, false);

    while (Window.isOpen())
    {
            checkInput();
            update();
            render();
    }
}

void Engine::checkInput()
{
    sf::Event InputEvent;
    while (Window.pollEvent(InputEvent))
    {
        if (InputEvent.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            Window.close(); // TODO implement checks for more input events once we're done testing
        }
    }
}

void Engine::update()
{
    // Apply the flocking algorithm to our Swarm
    swarm.applyBehaviour();
}

void Engine::render()
{
    Window.clear();
    for (int i = 0; i < swarm.getMaxFlockSize(); i++)
    {
        Window.draw(swarm.flock[i].getShape());
    }
    Window.display();
}
