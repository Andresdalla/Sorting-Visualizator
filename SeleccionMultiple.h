#pragma once
#include <SFML/Graphics.hpp>

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
	sf::Text algoritmos[9];
	int actual;
	sf::RectangleShape cuadro;
	sf::CircleShape trianguloIzq;
	sf::CircleShape trianguloDer;

};

