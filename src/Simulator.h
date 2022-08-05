#include <SFML/Graphics.hpp>

class Simulator
{
public:
    Simulator(int width, int height);

    void DrawNextFrame(sf::RenderWindow& window);

private:
    sf::Shader shader;

    sf::RenderTexture renderTexture;

    sf::RectangleShape screen;
    sf::RectangleShape initialPixel;
};
