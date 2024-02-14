#pragma once
#include "SortWindow.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

SortWindow::SortWindow(float width,float height, int valor)
{
	int anchoBarras = width / valor;
	const int espacioBarras = 2;
	int xPosition = 0;
	//para generar  alturas aleatorias
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> heightDist(0, 500);
	for (int i = 0; i < valor; ++i) {
		int barHeight = heightDist(gen); // Altura aleatoria
		sf::RectangleShape bar(sf::Vector2f(anchoBarras, barHeight));
		bar.setPosition(xPosition, height - barHeight); // Comienza desde el borde inferior
		bar.setFillColor(sf::Color::Magenta); // Color de las barras (puedes cambiarlo)
		barras.push_back(bar);
		xPosition += anchoBarras + espacioBarras; // Actualizar la posición horizontal
	}
}

void SortWindow::Draw(sf::RenderWindow& window)
{
	for (const auto& bar : barras) {
		window.draw(bar);
	}
}

void SortWindow::swap(int i)
{
	sf::RectangleShape temp = barras[i];
	float tempX = barras[i].getPosition().x;
	float nextBarX = barras[i + 1].getPosition().x;

	// Intercambiar las barras
	barras[i] = barras[i + 1];
	barras[i + 1] = temp;

	// Asegúrate de que las barras estén en la posición correcta después del intercambio
	barras[i].setPosition(tempX, barras[i].getPosition().y);
	barras[i + 1].setPosition(nextBarX, barras[i + 1].getPosition().y);

}

std::vector<sf::RectangleShape> SortWindow::getListaBarras()
{
	return barras;
}

void SortWindow::setColorBar(int i)
{
	barras[i].setFillColor(sf::Color::Green);
}

void SortWindow::setDefaultColorBar(int i)
{
	barras[i].setFillColor(sf::Color::Magenta);

}

