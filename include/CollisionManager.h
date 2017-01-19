#pragma once

#include "SFML\Graphics.hpp"

class CollisionManager
{


public: 
	CollisionManager();//collision manager instance
	~CollisionManager();
	bool collision(sf::RectangleShape, sf::RectangleShape);//returns wether or not two rectangles have collided

private:


};