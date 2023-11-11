#pragma once
#include <SFML/Graphics.hpp>
#include <queue>
#include "LineWithroundOff.h"

class TheInvisible : public sf::Drawable
{
public:
	TheInvisible(int howMany);
	void update(const sf::RenderWindow& win);
	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
private:
	std::vector<LineWithRoundOff> lines;
	uint32_t circlethatShouldBechanged;
};