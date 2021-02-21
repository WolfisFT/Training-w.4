#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/GameObject.h"
class Cursor :
	public GameObject
{
public:
	Cursor();
	~Cursor();

	Input* input;

	void setInput(Input*);
	void update(float);

private:
	sf::Texture mouseIcon;

	//Mouse position
	float Xpos;
	float Ypos;
};




