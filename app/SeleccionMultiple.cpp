#include "SeleccionMultiple.h"
#include <iostream>

SeleccionMultiple::SeleccionMultiple(sf::Vector2f pos)
{
	actual = 0;
	cuadro.setFillColor(sf::Color::Black);
	cuadro.setOutlineColor(sf::Color::Magenta);
	cuadro.setOutlineThickness(3);
	cuadro.setSize(sf::Vector2f(300, 30));
	cuadro.setPosition(pos);
	cuadro.setOrigin(0, cuadro.getSize().y / 2);
	trianguloIzq.setRadius(8);
	trianguloIzq.setPointCount(3);
	trianguloIzq.setPosition(pos.x - 25, pos.y - 10);
	trianguloIzq.rotate(30);
	trianguloIzq.setFillColor(sf::Color::Magenta);
	trianguloDer.setRadius(8);
	trianguloDer.setPointCount(3);
	trianguloDer.setPosition(pos.x + cuadro.getSize().x + 30, pos.y - 10);
	trianguloDer.rotate(90);
	trianguloDer.setFillColor(sf::Color::Magenta);
	//opciones para elegir:
	sf::Font font;
	if (!font.loadFromFile("fuente.ttf")) {
		std::cout << "No hay fuente";
	}
}

void SeleccionMultiple::draw(sf::RenderWindow& window)
{
	window.draw(cuadro);
	window.draw(trianguloDer);
	window.draw(trianguloIzq);
}

void SeleccionMultiple::moverDerecha()
{
	if (actual < 8) {
		actual++;
	}
	else {
		actual = 0;
	}
}

void SeleccionMultiple::moverIzquierda()
{
	if (actual > 0) {
		actual--;
	}
	else {
		actual = 8;
	}
}

int SeleccionMultiple::getActual()
{
	return actual;
}

void SeleccionMultiple::setTrianguloIzqColor()
{
	trianguloIzq.setFillColor(sf::Color::White);
	trianguloDer.setFillColor(sf::Color::Magenta);

}

void SeleccionMultiple::setTrianguloDerColor()
{
	trianguloDer.setFillColor(sf::Color::White);
	trianguloIzq.setFillColor(sf::Color::Magenta);
}

void SeleccionMultiple::setTriangulosDef()
{
	trianguloDer.setFillColor(sf::Color::Magenta);
	trianguloIzq.setFillColor(sf::Color::Magenta);
}
