// SortApplic.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "inputNumerico.h"
#include "SeleccionMultiple.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 720), "Sort App", sf::Style::Default);
	Menu menu(window.getSize().x, window.getSize().y);
	int opcionElegida = 0;
	sf::Text valor;
	sf::Font font;
	font.loadFromFile("fuente.ttf");
	valor.setFont(font);
	valor.setPosition(805, 155);
	valor.setCharacterSize(23);
	valor.setString("0");
	valor.setFillColor(sf::Color::Magenta);
	sf::Vector2f posInputNumerico(500,170);
	sf::Vector2f posSeleccionMultiple(500, 320);
	inputNumerico input(posInputNumerico);
	SeleccionMultiple selec(posSeleccionMultiple);
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

	while (window.isOpen())
	{
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			if (evt.type == sf::Event::Closed) {
				window.close();
			}

			if (evt.type == sf::Event::KeyPressed) {
				if (evt.key.code == sf::Keyboard::Up) {
					menu.MoveUp();
					opcionElegida = menu.MenuPressed();
					selec.setTriangulosDef();

					break;
				}
				if (evt.key.code == sf::Keyboard::Down) {
					menu.MoveDown();
					opcionElegida = menu.MenuPressed();
					selec.setTriangulosDef();

					break;
				}
				if (evt.key.code == sf::Keyboard::Enter) {
					if (opcionElegida == 1) {
						menu.setTextColor(1, sf::Color::Yellow);
					}
					if (opcionElegida == 2) {
						window.close();
					}
				}
				else if ((evt.key.code == sf::Keyboard::Left) && (opcionElegida == 0) && (input.getPerilla().getPosition().x > input.getMinPos())) {
					input.decrmentarValor(posInputNumerico);
					valor.setString(std::to_string(input.getValor()));
				}
				else if ((evt.key.code == sf::Keyboard::Right) && (opcionElegida == 0) && (input.getPerilla().getPosition().x < input.getMaxPos())) {
					input.aumentarValor(posInputNumerico);
					valor.setString(std::to_string(input.getValor()));
				}
				else if ((evt.key.code == sf::Keyboard::Left) && (opcionElegida == 1)) {
					selec.moverIzquierda();
					selec.setTrianguloIzqColor();
				}
				else if ((evt.key.code == sf::Keyboard::Right) && (opcionElegida == 1)) {
					selec.moverDerecha();
					selec.setTrianguloDerColor();
				}
				else if ((opcionElegida == 2)) {
				}
			}
		}
		window.clear();
		menu.Draw(window);
		input.Draw(window);
		selec.draw(window);
		window.draw(valor);
		window.display();
	}

}

