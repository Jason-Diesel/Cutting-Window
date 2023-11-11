#include "LineWithroundOff.h"

static float lenght(sf::Vector2f startPoint, sf::Vector2f endPoint)
{
	return sqrt(
		(startPoint.x - endPoint.x) *
		(startPoint.x - endPoint.x) + 
		(startPoint.y - endPoint.y) *
		(startPoint.y - endPoint.y)
	);
}

LineWithRoundOff::LineWithRoundOff()
{
	start.setRadius(size/2);
	start.setOrigin(size/2,size/2);
	middle.setOrigin(0, size/2);
}

void LineWithRoundOff::change(sf::Vector2f startPoint, sf::Vector2f endPoint)
{
	pos = endPoint;
	start.setPosition(startPoint);
	middle.setPosition(startPoint);
	middle.setSize(sf::Vector2f(lenght(startPoint, endPoint), size));
	middle.setRotation(atan2(endPoint.y - startPoint.y, endPoint.x - startPoint.x) * (180.0 / 3.141592653589793238463));
}

void LineWithRoundOff::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(middle);
	target.draw(start);
}