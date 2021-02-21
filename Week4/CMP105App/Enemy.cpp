#include "Enemy.h"

Enemy::Enemy()
{
	// initialise 1st enemy
	enemyTexture.loadFromFile("gfx/Goomba.png");
	setSize(sf::Vector2f(50, 50));
	setVelocity(300, 0);
	setPosition(300, 85);
	setTexture(&enemyTexture);

	enemyVelocityX = 300.0f;
	enemyVelocityY = 300.0f;
}

Enemy::Enemy(std::string goomba)
{
	//initialise 2nd enemy
	enemyTexture1.loadFromFile(goomba);
	setSize(sf::Vector2f(50, 50));
	setVelocity(300, 0);
	setPosition(600, 500);
	setTexture(&enemyTexture1);

	enemyVelocityX = -150.0f;
	enemyVelocityY = 300.0f;
}

Enemy::~Enemy()
{

}



void Enemy::update(float dt, sf::RenderWindow* window)
{
	//updating enemy movement 
	move(enemyVelocityX * dt, enemyVelocityY * dt);

	//checking for window borders and making
	//enemy "bounce" once it hits the border
	sf::Vector2u WindowPos = window->getSize();
	sf::Vector2f enemyPos = getPosition();
	float BoundsX = enemyPos.x + getLocalBounds().width;
	float BoundsY = enemyPos.y + getLocalBounds().width;

	if (BoundsX > WindowPos.x || enemyPos.x < 0)
	{
		enemyVelocityX = enemyVelocityX * (-1);
	}
	if (BoundsY > WindowPos.y || enemyPos.y < 0)
	{
		enemyVelocityY = enemyVelocityY * (-1);
	}
	
}