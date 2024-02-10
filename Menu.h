#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextBox.h"
class Menu

{
public:
	Menu(float width, float height);
	
	void Draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	//especie de getter de menuselected
	
	int MenuPressed() {
		return MenuSelected;
	}
	
	void setTextColor(int index, sf::Color color) {
		// Asegúrate de que el índice es válido
			menu[index].setFillColor(color);
	}

private:
	int MenuSelected;
	sf::Font font;
	sf::Text menu[3];
};

