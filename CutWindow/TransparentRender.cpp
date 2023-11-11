#include "TransparentRender.h"

TransparentRender::TransparentRender(float windowHeight, float windowWidth)
{
    if (glewInit() != GLEW_OK) {
        exit(-1);
    }

    if (!transparentShader.loadFromFile("TransparentVertexShader.vert", sf::Shader::Vertex))
	{
		std::cout << "cannot load vertex shader" << std::endl;
	}
	if (!transparentShader.loadFromFile("TransparentPixelShader.frag", sf::Shader::Fragment))
	{
		std::cout << "cannot load Pixel shader" << std::endl;
	}

	//Create GBuffer
	glGenFramebuffers(1, &gBuffer);
	glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);

	glGenTextures(1, &gTexture);
	glBindTexture(GL_TEXTURE_2D, gTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, 800, 600, 0, GL_RGBA, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gTexture, 0);

	
}

void TransparentRender::firstPass()
{
	glBindFramebuffer(GL_FRAMEBUFFER, gBuffer);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void TransparentRender::secondPass()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, gBuffer);
}

TransparentRender::~TransparentRender()
{

}

sf::Shader& TransparentRender::getShader()
{
	return this->transparentShader;
}

