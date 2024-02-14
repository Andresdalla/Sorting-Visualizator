#pragma once
#include "SortWindow.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

SortWindow::SortWindow(float width, float height, int valor)
{
	const int espacioBarras = 2;
	int anchoBarras = (width - espacioBarras * (valor - 1)) / valor;
	int xPosition = 0;

	//para generar  alturas aleatorias
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> heightDist(0, 500);

	for (int i = 0; i < valor; ++i) {
		int barHeight = heightDist(gen); 
		sf::RectangleShape bar(sf::Vector2f(anchoBarras, barHeight));
		bar.setPosition(xPosition, height - barHeight); 
		bar.setFillColor(sf::Color::Magenta); 
		barras.push_back(bar);
		xPosition += anchoBarras + espacioBarras; 
	}
}


void SortWindow::Draw(sf::RenderWindow& window)
{
	for (const auto& bar : barras) {
		window.draw(bar);
	}
}

void SortWindow::swap(int i,int j)
{
	barras[i].setFillColor(sf::Color::Green);
	sf::RectangleShape temp = barras[i];
	float tempX = barras[i].getPosition().x;
	float nextBarX = barras[j].getPosition().x;
	barras[i] = barras[j];
	barras[j] = temp;
	barras[i].setPosition(tempX, barras[i].getPosition().y);
	barras[j].setPosition(nextBarX, barras[j].getPosition().y);
	barras[i].setFillColor(sf::Color::Magenta);
	barras[j].setFillColor(sf::Color::Green);
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

