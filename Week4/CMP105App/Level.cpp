#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");

	testSprite.setTexture(&texture);
	testSprite.setSize(sf::Vector2f(100, 100));
	testSprite.setPosition(100, 100);

	//setting Player class object's input
	playerSprite.setInput(input);

	//initialising 2nd enemy as a constructor
	//different from the first enemy
	enemySprite1.Enemy::Enemy(std::string("gfx/Goomba.png"));

	//setting cursor input and hiding 
	//Windows default icon
	cursorIcon.setInput(input);
	window->setMouseCursorVisible(false);

	//setting the background
	levelPic.setInput(input);


	


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	//calling a Player class and a Background class
	//handleinput() functions
	playerSprite.handleInput(dt);
	levelPic.handleInput(dt);

	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	
}

// Update game objects
void Level::update(float dt)
{
	//calling the updates for player, enemies
	//cursor and background
	//passing 'window' to make use of window->getSize() function
	levelPic.update(dt, window);
	enemySprite.update(dt, window);
	enemySprite1.update(dt, window);
	playerSprite.update(dt, window);
	cursorIcon.update(dt);

	
}

// Render level
void Level::render()
{
	beginDraw();
	
	//window->draw(testSprite);
	window->draw(levelPic);
	window->draw(playerSprite);
	window->draw(enemySprite);
	window->draw(enemySprite1);
	window->draw(cursorIcon);

	endDraw();
}
