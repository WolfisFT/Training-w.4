#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"

class Player :
	public GameObject
{
public:
	Player();
	~Player();

	Input* input;

	sf::RenderWindow* window;

	void setInput(Input*);
	void handleInput(float);
	void update(float, sf::RenderWindow*);


private:
	sf::Texture playerTexture;

	bool Rgo = 1;	//permission for "D" key to make a move
	bool Lgo = 1;	//permission for "A" key to make a move
	bool UPgo = 1;	//permission for "W" key to make a move
	bool DOWNgo = 1;//permission for "S" key to make a move

};

