#include <SFML/Graphics.hpp>
#include "Simulator.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::None);

    sf::Clock clock;

    float deltaTime = 0.0f;

    window.setVerticalSyncEnabled(true);

    Simulator simulator(800, 600);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (clock.getElapsedTime().asSeconds() >= 1.0f)
        {
            window.clear();

            simulator.DrawNextFrame(window);

            window.display();

            clock.restart();
        }
    }
}
