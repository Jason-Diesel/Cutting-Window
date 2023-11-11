#pragma once
#include <SFML/Graphics.hpp>

class LineWithRoundOff : public sf::Drawable
{
public:
	LineWithRoundOff();
	void change(sf::Vector2f startPoint, sf::Vector2f endPoint);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	sf::Vector2f pos;
	const int size = 50;
private:
	sf::RectangleShape middle;
	sf::CircleShape start;
};
