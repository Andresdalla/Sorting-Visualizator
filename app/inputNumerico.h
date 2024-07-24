#pragma once
#include <SFML/Graphics.hpp>
class inputNumerico
{
public:
	inputNumerico(sf::Vector2f);
	void Draw(sf::RenderWindow& window);
	void aumentarValor(sf::Vector2f& pos);
	void decrmentarValor(sf::Vector2f& pos);
	int getValor();
	int getMaxPos();
	int getMinPos();
	sf::CircleShape getPerilla();
	sf::RectangleShape getbarra();
	void setMaxPos(int maxP);
	void setMinPos(int minP);

private:
	sf::CircleShape perilla;
	sf::RectangleShape barra;
	int valor;
	int minPos;
	int maxPos;
};

