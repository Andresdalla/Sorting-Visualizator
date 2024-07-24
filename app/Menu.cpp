#include "Menu.h"
#include <iostream>

Menu::Menu(float width, float height) 
{
	if (!font.loadFromFile("fuente.ttf")) {
		std::cout << "No hay fuente";
	}
	//opcion 1
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::White);
	menu[0].setString("Cantidad para el sort");
	menu[0].setCharacterSize(30);
	menu[0].setPosition(50,250);

	//opcion 2
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Tipo de Sorting");
	menu[1].setCharacterSize(30);
	menu[1].setPosition(50, 400);
	//Exit
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Comenzar");
	menu[2].setCharacterSize(30);
	menu[2].setPosition(50, 550);

	MenuSelected = -1;
}
void Menu::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	//para chequear de qe no se vaya de rango
	if (MenuSelected - 1 >= 0) {
		menu[MenuSelected].setFillColor(sf::Color::White);
		
		MenuSelected--;
		
		if (MenuSelected == -1) {
			MenuSelected = 2;
		}
		menu[MenuSelected].setFillColor(sf::Color::Magenta);
	}

	
}

void Menu::MoveDown()
{
	//para chequear de qe no se vaya de rango
	if (MenuSelected + 1 <= 3) {
		menu[MenuSelected].setFillColor(sf::Color::White);
		MenuSelected++;
		if (MenuSelected == 3) {
			MenuSelected = 0;
		}
		menu[MenuSelected].setFillColor(sf::Color::Magenta);
	}


}