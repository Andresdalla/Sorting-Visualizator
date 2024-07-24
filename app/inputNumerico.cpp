#include "inputNumerico.h"

inputNumerico::inputNumerico(sf::Vector2f pos)
{
	perilla.setRadius(10);
	perilla.setOrigin(10, 10);
	barra.setSize(sf::Vector2f(250, 7));
	barra.setOrigin(0, barra.getSize().y / 2);
	perilla.setFillColor(sf::Color::Magenta);
	barra.setFillColor(sf::Color::Magenta);
	perilla.setPosition(pos);
	barra.setPosition(pos);
	valor = 0;
	minPos = pos.x;
	maxPos = pos.x + barra.getSize().x;

}

void inputNumerico::Draw(sf::RenderWindow& window)
{
	window.draw(perilla);
	window.draw(barra);

}

void inputNumerico::aumentarValor(sf::Vector2f& pos)
{
	pos.x += 10;
	valor += 5;
	perilla.setPosition(pos);
}

void inputNumerico::decrmentarValor(sf::Vector2f& pos)
{
	pos.x -= 10;
	valor -= 5;
	perilla.setPosition(pos);
}

int inputNumerico::getValor()
{
	return valor;
}

int inputNumerico::getMaxPos()
{
	return maxPos;
}

int inputNumerico::getMinPos()
{
	return minPos;
}

sf::CircleShape inputNumerico::getPerilla()
{
	return perilla;
}

sf::RectangleShape inputNumerico::getbarra()
{
	return barra;
}

void inputNumerico::setMaxPos(int maxp)
{
	maxPos = maxp;
}

void inputNumerico::setMinPos(int minP)
{
	minP = minP;
}

