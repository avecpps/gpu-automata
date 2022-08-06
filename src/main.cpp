#include <SFML/Graphics.hpp>
#include "Simulator.h"

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::None);

    sf::Clock clock;

    window.setVerticalSyncEnabled(true);

    std::string shaderPath = "shaders/fragmentShader.glsl";

    if (argc > 1)
    {
        shaderPath = std::string(argv[1]);
    }

    Simulator simulator(800, 600, shaderPath);

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

        if (clock.getElapsedTime().asSeconds() >= 1.0f / 20.0f)
        {
            window.clear();

            simulator.DrawNextFrame(window);

            window.display();

            clock.restart();
        }
    }
}
