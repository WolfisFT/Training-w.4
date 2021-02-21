#include "Cursor.h"

Cursor::Cursor()
{
	// initialise game objects
	mouseIcon.loadFromFile("gfx/Cursor.png");
	setSize(sf::Vector2f(40, 40));
	setTexture(&mouseIcon);
}

Cursor::~Cursor()
{

}


void Cursor::setInput(Input* in)
{
	input = in;
}


void Cursor::update(float dt)
{
	//updating the position of a cursor
	//setting it at the same coordinates
	//as mouse has
	Xpos = (float)input->getMouseX();
	Ypos = (float)input->getMouseY();
	setPosition(Xpos, Ypos);
}