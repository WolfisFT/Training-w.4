#include "Player.h"

Player::Player()
{
	// initialise game objects
	playerTexture.loadFromFile("gfx/Mushroom.png");
	setSize(sf::Vector2f(50, 50));
	setVelocity(0, 0);
	setPosition(120, 500);
	setTexture(&playerTexture);

}

Player::~Player()
{
}


void Player::setInput(Input* in)
{
	input = in;
}


void Player::handleInput(float dt)
{
	bool LEFT = input->isKeyDown(sf::Keyboard::A);
	bool RIGHT = input->isKeyDown(sf::Keyboard::D);
	bool UP = input->isKeyDown(sf::Keyboard::W);
	bool DOWN = input->isKeyDown(sf::Keyboard::S);

	
	if (RIGHT)
	{
		//if "D" key is able to make a move
		//then go in positive direction on x-axis
		if (Rgo == 1)
		{
			setVelocity(300, 0);
			//allow for "A" key to make a move
			//at any time
			Lgo = 1;
		}
		move(velocity * dt);
	}

	if (LEFT)
	{
		//if "A" key is able to make a move
		//then go in negative direction on x-axis
		if (Lgo == 1)
		{
			setVelocity(-300, 0);
			//allow for "D" key to make a move
			//at any time
			Rgo = 1;
		}
		move(velocity * dt);
	}

	if (UP)
	{
		if (UPgo == 1)
		{
			setVelocity(0, 300);
			//allow for "S" key to make a move
			//at any time
			DOWNgo = 1;
		}
		move(-velocity * dt);
	}

	if (DOWN)
	{
		if (DOWNgo == 1)
		{
			setVelocity(0, -300);
			UPgo = 1;
		}
		move(-velocity * dt);
	}


}


void Player::update(float dt, sf::RenderWindow* window)
{
	sf::Vector2u WindowPos = window->getSize();
	sf::Vector2f playerPos = getPosition();
	float BoundsX = playerPos.x + getLocalBounds().width;
	float BoundsY = playerPos.y + getLocalBounds().width;

	if (BoundsX > WindowPos.x)
	{
		//Once we hit right side of our wndow
		//stop the object (speed = 0),
		//but also stop "Right" key from changing speed value
		setVelocity(0, 0);
		Rgo = 0;
	}
	else if (playerPos.x < 0)
	{
		//Once we hit left side of our wndow
		//stop the object (speed = 0),
		//but also stop "Left" key from changing speed value
		setVelocity(0, 0);
		Lgo = 0;
	}

	if (BoundsY > WindowPos.y)
	{
		//Once we hit bottom side of our wndow
		//stop the object (speed = 0),
		//but also stop "Down" key from changing speed value
		setVelocity(0, 0);
		DOWNgo = 0;
	}
	else if (playerPos.y < 0)
	{
		//Once we hit top side of our wndow
		//stop the object (speed = 0),
		//but also stop "Up" key from changing speed value
		setVelocity(0, 0);
		UPgo = 0;
	}


}

