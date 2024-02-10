#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextBox {
private:
    sf::RectangleShape box;
    sf::Text text;
    std::string input;

public:
    TextBox(int x, int y, int width, int height);

    void handleInput(sf::Event event);

    void draw(sf::RenderWindow& window);

    std::string getText();
};