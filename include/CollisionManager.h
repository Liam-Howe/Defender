#pragma once

#include "SFML\Graphics.hpp"

class CollisionManager
{


public: 
	CollisionManager();
	~CollisionManager();
	bool collision(sf::RectangleShape, sf::RectangleShape);

private:


};