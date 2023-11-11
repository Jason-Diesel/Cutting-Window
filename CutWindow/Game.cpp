#include "Game.h"

void Game::MakeWindowTransparent()
{
	HWND hwnd = win.getSystemHandle();
	//Make style to none
	//DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
	//style &= ~WS_OVERLAPPEDWINDOW;
	//style |= WS_POPUP;
	//::SetWindowLong(hwnd, GWL_STYLE, style);

	DWM_BLURBEHIND bb = {0};
	bb.dwFlags = DWM_BB_ENABLE | DWM_BB_BLURREGION;;
	bb.fEnable = true;
	bb.fTransitionOnMaximized = false;
	bb.hRgnBlur = CreateRectRgn(-1, -1, 0, 0);
	DwmEnableBlurBehindWindow(hwnd, &bb);
}

Game::Game():
	win(sf::VideoMode(800, 600), "SFML window"),
	TR(800,600),
	TI(20)
{	
	done = false;
	win.setFramerateLimit(50);
	MakeWindowTransparent();
	glDisable(GL_BLEND);


	playArea.setFillColor(sf::Color::White);
	playArea.setPosition(0,0);
	playArea.setSize(sf::Vector2f(800,600));

	playArea2.setFillColor(sf::Color::White);
	playArea2.setPosition(400,0);
	playArea2.setSize(sf::Vector2f(400,600));

	if (!normalDraw.loadFromFile("NormalDrawVertex.vert", sf::Shader::Vertex))
	{
		std::cout << "cannot load vertex shader" << std::endl;
		exit(-1);
	}
	if (!normalDraw.loadFromFile("NormalDrawPixel.frag", sf::Shader::Fragment))
	{
		std::cout << "cannot load Pixel shader" << std::endl;
		exit(-1);
	}
}

Game::~Game()
{
}

bool Game::Update(float dt)
{
	TI.update(win);
	return done;
}

void Game::Render()
{
	static int i = 0;
	win.clear(sf::Color(0,0,0,0));

	TR.firstPass();

	win.draw(TI);

	TR.secondPass();

	win.draw(playArea, &normalDraw);
	win.draw(playArea2, &normalDraw);

	win.display();
}

void Game::HandleEvents()
{
	sf::Event event;
	while (win.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			win.close();
			done = true;
		}
	}
}
