#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window", sf::Style::None);

    sf::Clock clock;

    float deltaTime = 0.0f;

    window.setVerticalSyncEnabled(true);

    sf::RenderTexture renderTexture;

    renderTexture.create(window.getSize().x, window.getSize().y);

    sf::Sprite renderSprite;

    renderSprite.setTexture(renderTexture.getTexture());
    
    sf::RectangleShape screen(sf::Vector2f(window.getSize().x, window.getSize().y));
    sf::RectangleShape initialPixel(sf::Vector2f(64.0f, 64.0f));

    initialPixel.setFillColor(sf::Color::White);

    sf::Shader shader;

    shader.loadFromFile("shaders/fragmentShader.glsl", sf::Shader::Type::Fragment);

    screen.setFillColor(sf::Color::Black);

    renderTexture.draw(screen);
    renderTexture.draw(initialPixel);

    renderTexture.display();
    
    screen.setTexture(&renderTexture.getTexture());
    
    screen.setFillColor(sf::Color::White);

    window.clear();

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

            renderTexture.draw(screen, &shader);

            renderTexture.display();

            window.draw(screen);

            window.display();

            clock.restart();
        }

    }
}
