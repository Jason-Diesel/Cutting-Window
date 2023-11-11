#include "TheInvisible.h"

TheInvisible::TheInvisible(int howMany)
{
	circlethatShouldBechanged = 0;
	lines.resize(howMany);
}

void TheInvisible::update(const sf::RenderWindow& win)
{
	sf::Vector2f lastPos = lines[circlethatShouldBechanged].pos;
	circlethatShouldBechanged++;
	if(circlethatShouldBechanged >= lines.size()){
		circlethatShouldBechanged = 0;
	}
	
	lines[circlethatShouldBechanged].change(lastPos, sf::Vector2f(sf::Mouse::getPosition(win)));
}

void TheInvisible::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for(int i = 0; i < lines.size(); i++){
		target.draw(lines[i]);
	}
}