// SortApplic.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "inputNumerico.h"
#include "SeleccionMultiple.h"
#include "SortWindow.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 720), "Sort App", sf::Style::Default);
	Menu menu(window.getSize().x, window.getSize().y);
	int opcionElegida = 0;
	sf::Text valor;
	sf::Text titulo;
	sf::Font font;
	sf::Vector2f posInputNumerico(500, 275);
	sf::Vector2f posSeleccionMultiple(500, 420);
	sf::Text texto;
	sf::Font fontTitulo;
	sf::Text aviso;
	fontTitulo.loadFromFile("titulo.ttf");
	font.loadFromFile("fuente.ttf");
	valor.setFont(font);
	valor.setPosition(805, 255);
	valor.setCharacterSize(23);
	valor.setString("0");
	valor.setFillColor(sf::Color::Magenta);
	inputNumerico input(posInputNumerico);
	SeleccionMultiple selec(posSeleccionMultiple);
	std::vector<std::string> algoritmos = {
		"1. Selection sort",
		"2. Bubble sort",
		"3. Insertion sort",
		"4. Merge sort",
		"5. Quick sort",
		"6. Heap sort",
		"7. Counting sort",
		"8. Radix sort",
		"9. Bucket sort"
	};
	texto.setFillColor(sf::Color::Magenta);
	texto.setFont(font);
	texto.setCharacterSize(25);
	texto.setPosition(550, 403);
	texto.setString("1. Selection sort");
	titulo.setFillColor(sf::Color::Magenta);
	titulo.setFont(fontTitulo);
	titulo.setCharacterSize(50);
	titulo.setPosition(140, 80);
	titulo.setString("Sorting Visualizator");
	aviso.setFillColor(sf::Color::Magenta);
	aviso.setFont(font);
	aviso.setCharacterSize(20);
	aviso.setPosition(window.getSize().x -800, window.getSize().y - 30);
	aviso.setString("Solo disponibles bubble y selection sort. Sigue en desarrollo");
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
					sf::RenderWindow sort(sf::VideoMode(960, 720), "Sort App", sf::Style::Default);
					SortWindow sortwindow(960, sort.getSize().y, input.getValor());

					if (opcionElegida == 2) {
						while (sort.isOpen()) {
							sf::Event evt2;
							while (sort.pollEvent(evt2)) {
								if (evt2.type == sf::Event::Closed) {
									sort.close();
								}
								if (evt2.type == sf::Event::KeyReleased) {
									if (evt2.key.code == sf::Keyboard::Escape) {
										sort.close();
									}
									if (evt2.key.code == sf::Keyboard::Enter) {
										int itera = 1;
										sf::Text tit = texto;
										tit.setFont(font);
										tit.setPosition(20, 20);
										tit.setCharacterSize(30);
										if (tit.getString() == "2. Bubble sort") {
											for (int i = 0; i < sortwindow.getListaBarras().size(); i++) {
												for (int j = 0; j < sortwindow.getListaBarras().size() - 1; j++) {
													if (sortwindow.getListaBarras()[j].getSize().y > sortwindow.getListaBarras()[j + 1].getSize().y) {

														sortwindow.swap(j, j+1);
														sf::sleep(sf::milliseconds(10));
													}
													sort.clear();
													sort.draw(tit);
													sortwindow.Draw(sort);
													sort.display();
												}

											}
										}
										if (tit.getString() == "1. Selection sort") {
											for (int i = 0; i < sortwindow.getListaBarras().size() - 1; i++) {
												int min_idx = i;
												for (int j = i + 1; j < sortwindow.getListaBarras().size(); j++) {
													if (sortwindow.getListaBarras()[j].getSize().y < sortwindow.getListaBarras()[min_idx].getSize().y) {
														sortwindow.swap(j, min_idx);
														sf::sleep(sf::milliseconds(20));
													}
													sort.clear();
													sort.draw(tit);
													sortwindow.Draw(sort);
													sort.display();
												}

											}
										}
										
									}
								}

								
							}
							sort.clear();
							sortwindow.Draw(sort);
							sort.display();
						}
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
					texto.setString(algoritmos[selec.getActual()]);
				}
				else if ((evt.key.code == sf::Keyboard::Right) && (opcionElegida == 1)) {
					selec.moverDerecha();
					texto.setString(algoritmos[selec.getActual()]);
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
		window.draw(texto);
		window.draw(titulo);
		window.draw(valor);
		window.draw(aviso);
		window.display();

	}

}



