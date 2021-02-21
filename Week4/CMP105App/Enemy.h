#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"
class Enemy :
	public GameObject
{
public:
	Enemy();
	Enemy(std::string);	//constructor for a 2nd enemy
	~Enemy();

	sf::RenderWindow* window;

	
	void update(float, sf::RenderWindow*);

private:
	sf::Texture enemyTexture;
	sf::Texture enemyTexture1;

	float enemyVelocityX;
	float enemyVelocityY;
};

