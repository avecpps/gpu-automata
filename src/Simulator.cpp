#include "Simulator.h"

Simulator::Simulator(int width, int height, const std::string& shaderPath, float scale)
{
    renderTexture.create((float)width / scale, (float)height / scale);

    screen.setSize(sf::Vector2f((float)width / scale, (float)height / scale));
    screen.setFillColor(sf::Color::Black);

    scaledScreen.setSize(screen.getSize() * scale);
    scaledScreen.setTexture(&renderTexture.getTexture());

    initialPixel.setPosition(sf::Vector2f((float)width / (2.0f * scale), 0.0f));
    initialPixel.setSize(sf::Vector2f(1.0f, 1080.0f / scale));
    initialPixel.setFillColor(sf::Color::White);

    renderTexture.clear(sf::Color::Black);

    renderTexture.draw(screen);
    renderTexture.draw(initialPixel);

    renderTexture.display();

    screen.setFillColor(sf::Color::White);
    screen.setTexture(&renderTexture.getTexture());

    shader.loadFromFile(shaderPath, sf::Shader::Type::Fragment);

    shader.setUniform("width", (int)((float)width / scale));
    shader.setUniform("height", (int)((float)height / scale));
}

void Simulator::DrawNextFrame(sf::RenderWindow &window)
{
    renderTexture.draw(screen, &shader);

    renderTexture.display();

    window.draw(scaledScreen);
}
