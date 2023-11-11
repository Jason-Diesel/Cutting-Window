#pragma once
#include "TransparentRender.h"
#include "TheInvisible.h"
#include <Windows.h>
#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")
#pragma comment(lib, "opengl32.lib")
#include <iostream>




class Game {
private:
	sf::RenderWindow win;
	bool done;

	sf::RectangleShape playArea;
	sf::RectangleShape playArea2;
	TheInvisible TI;
	
	sf::Shader normalDraw;
	TransparentRender TR;

	void MakeWindowTransparent();
public:
	Game();
	virtual ~Game();
	bool Update(float dt);
	void Render();
	void HandleEvents();
};