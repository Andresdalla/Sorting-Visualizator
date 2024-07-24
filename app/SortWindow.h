#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class SortWindow
{
public:
	SortWindow(float widht, float height, int valor);
	void Draw(sf::RenderWindow& window);
	void swap(int i, int j);
	std::vector<sf::RectangleShape> getListaBarras();
	void setColorBar(int i);
	void setDefaultColorBar(int i);

private:
	std::vector<sf::RectangleShape> barras;
	//pensalas
};

