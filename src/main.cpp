#include <SFML/Graphics.hpp>
#include <SFML/System/Sleep.hpp>
#include "Simulator.h"

int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML window", sf::Style::None);

    float scale = 8.0f;

    sf::Clock clock;

    window.setVerticalSyncEnabled(true);

    std::string shaderPath = "shaders/fragmentShader.glsl";

    if (argc > 1)
    {
        shaderPath = std::string(argv[1]);
    }

    Simulator simulator(window.getSize().x, window.getSize().y, shaderPath, scale);

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

        if (clock.getElapsedTime().asSeconds() >= 1.0f / 10.0f)
        {
            window.clear();

            simulator.DrawNextFrame(window);

            window.display();

            clock.restart();
        }

        else
        {
            sf::sleep(sf::seconds(1.0f / 10.0f - clock.getElapsedTime().asSeconds()));
        }
    }
}
