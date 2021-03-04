#include "Background.h"


Background::Background()
{
	level.loadFromFile("gfx/Level1_1.png");
	setSize(sf::Vector2f(11038, 675));
	setTexture(&level);

	view.setSize(sf::Vector2f(1200.f, 675.f));
	view.setCenter(sf::Vector2f(view.getSize().x/2, view.getSize().y/2));
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
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if (Rgo == 1)
		{
			setVelocity(1000.f, 0.f);
			Lgo = 1;
		}
		view.move(velocity * dt);
	}
	
	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if (Lgo == 1)
		{
			setVelocity(-1000.f, 0.f);
			Rgo = 1;
		}
		view.move(velocity * dt);
	}
}

void Background::update(float dt, sf::RenderWindow* window)
{
	window->setView(view);

	sf::Vector2f ViewPos = view.getCenter();
	sf::Vector2u LevelPos = level.getSize();


	std::cout << ViewPos.x << "   LevelPOS: " << LevelPos.x << "\n";
	if (ViewPos.x > LevelPos.x )
	{

		//Once we hit right side of our wndow
		//stop the object (speed = 0),
		//but also stop "Right" key from changing speed value

		setVelocity(0, 0);
		Rgo = 0;
	}
	else if (ViewPos.x < view.getSize().x / 2)
	{
		//Once we hit left side of our wndow
		//stop the object (speed = 0),
		//but also stop "Left" key from changing speed value
		setVelocity(0, 0);
		Lgo = 0;
	}
}
