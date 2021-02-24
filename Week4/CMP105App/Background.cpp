#include "Background.h"


Background::Background()
{
	level.loadFromFile("gfx/Level1_1.png");
	setSize(sf::Vector2f(11038, 675));
	setTexture(&level);

}

Background::~Background()
{

}

void Background::setInput(Input* in)
{
	input = in;
}


void Background::handleInput(float dt)
{
	bool LEFT = input->isKeyDown(sf::Keyboard::Left);
	bool RIGHT = input->isKeyDown(sf::Keyboard::Right);

	if (RIGHT)
	{
		//if "Right" key is able to make a move
		//then go in positive direction on x-axis
		if (Rgo == 1)
		{
			setVelocity(-1000.f, 0.f);
			//allow for "Left" key to make a move
			//at any time
			Lgo = 1;
		}
		move(velocity *dt);
	}

	if (LEFT)
	{
		//if "Left" key is able to make a move
		//then go in negative direction on x-axis
		if (Lgo == 1)
		{
			setVelocity(1000.f, 0.f);
			//allow for "Right" key to make a move
			//at any time
			Rgo = 1;
		}
		move(velocity * dt);
	}

}

void Background::update(float dt)
{
	sf::Vector2f ViewPos = getPosition();
	sf::Vector2u LevelPos = level.getSize();


	std::cout << ViewPos.x *(-1)<< "   LevelPOS: " << LevelPos.x << "\n" ;
	if (ViewPos.x * (-1) > LevelPos.x -200)
	{

		//Once we hit right side of our wndow
		//stop the object (speed = 0),
		//but also stop "Right" key from changing speed value
	
		setVelocity(0, 0);
		Rgo = 0;
	}
	else if (ViewPos.x > 0)
	{
		//Once we hit left side of our wndow
		//stop the object (speed = 0),
		//but also stop "Left" key from changing speed value
		setVelocity(0, 0);
		Lgo = 0;
	}

}
