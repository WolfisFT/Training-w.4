#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"
class Background :
	public GameObject
{
public:
	Background();
	~Background();

	Input* input;
	sf::RenderWindow* window;
	sf::View view;

	void setInput(Input*);
	void handleInput(float);
	void update(float);
	

private:
	sf::Texture level;

	bool Rgo = 1;	//permission for "Right" key to make a move
	bool Lgo = 1;	//permission for "Left" key to make a move

};



