#include <SFML/Graphics.hpp>

class Simulator
{
public:
    Simulator(int width, int height, const std::string& shaderPath, float scale);

    void DrawNextFrame(sf::RenderWindow& window);

private:
    sf::Shader shader;

    sf::RenderTexture renderTexture;

    sf::RectangleShape screen;
    sf::RectangleShape initialPixel;

    sf::RectangleShape scaledScreen;
};
