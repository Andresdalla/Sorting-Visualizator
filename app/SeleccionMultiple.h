#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class SeleccionMultiple

{
public:
	SeleccionMultiple(sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	void moverDerecha();
	void moverIzquierda();
	int getActual();
	void setTrianguloIzqColor();
	void setTrianguloDerColor();
	void setTriangulosDef();

private:
	int actual;
	sf::RectangleShape cuadro;
	sf::CircleShape trianguloIzq;
	sf::CircleShape trianguloDer;
	sf::Text texto;
};

