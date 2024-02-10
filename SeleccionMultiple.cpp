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
	std::string sortingAlgorithms[] = {
		"1- Selection sort (selección)",
		"2- Bubble sort (burbuja)",
		"3- Insertion sort (inserción)",
		"4- Merge sort (combinación)",
		"5- Quick sort (rápida)",
		"6- Heap sort (montón)",
		"7- Counting sort (conteo)",
		"8- Radix sort (raíz)",
		"9- Bucket sort (cubo)"
	};
	for (int i = 0; i < 8; ++i) {
		algoritmos[i].setString(sortingAlgorithms[i]);
		algoritmos[i].setCharacterSize(30);
		algoritmos[i].setFillColor(sf::Color::Magenta);
		algoritmos[i].setPosition(250, 334);
	}
}

void SeleccionMultiple::draw(sf::RenderWindow& window)
{
	window.draw(cuadro);
	window.draw(trianguloDer);
	window.draw(trianguloIzq);
	window.draw(algoritmos[2]);

}

void SeleccionMultiple::moverDerecha()
{
	if (actual <= 9) {
		actual++;
	}
	else {
		actual = 0;
	}
}

void SeleccionMultiple::moverIzquierda()
{
	if (actual >= 0) {
		actual--;
	}
	else {
		actual = 9;
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
