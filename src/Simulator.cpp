#include "Simulator.h"

Simulator::Simulator(int width, int height)
{
    renderTexture.create(width, height);

    screen.setSize(sf::Vector2f(width, height));
    screen.setFillColor(sf::Color::Black);

    initialPixel.setSize(sf::Vector2f(64.0f, 64.0f));
    initialPixel.setFillColor(sf::Color::White);

    renderTexture.clear(sf::Color::Black);

    renderTexture.draw(screen);
    renderTexture.draw(initialPixel);

    renderTexture.display();

    screen.setFillColor(sf::Color::White);
    screen.setTexture(&renderTexture.getTexture());

    shader.loadFromFile("shaders/fragmentShader.glsl", sf::Shader::Type::Fragment);

    shader.setUniform("width", width);
    shader.setUniform("height", height);
}

void Simulator::DrawNextFrame(sf::RenderWindow &window)
{
    renderTexture.draw(screen, &shader);

    renderTexture.display();

    window.draw(screen);
}
