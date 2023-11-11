#pragma once
#include <gl/glew.h>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#define dataSize sizeof(bool) * (800*600)

class TransparentRender
{
public:
	TransparentRender(float windowHeight, float windowWidth);
	~TransparentRender();
	sf::Shader &getShader();

	void firstPass();
	void secondPass();
private:
	sf::Shader transparentShader;

	UINT32 gBuffer, gTexture;
	GLint DefFrameBuffer;
};