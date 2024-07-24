#pragma once
#include <SFML/Graphics.hpp>
class Inicio
{
public:
	Inicio(float width, float height);

	void Draw(sf::RenderWindow& window);
private:
	sf::Font font;
	sf::Text menu[1];
};

