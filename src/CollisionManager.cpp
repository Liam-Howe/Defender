#include "../include/CollisionManager.h"

CollisionManager::CollisionManager()
{

}
CollisionManager::~CollisionManager()
{

}
bool CollisionManager::collision(sf::RectangleShape _rect1, sf::RectangleShape _rect2)
{
	if (_rect1.getGlobalBounds().intersects(_rect2.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CollisionManager::circleRectcollision(sf::CircleShape circle, sf::RectangleShape rect)
{
	if (circle.getGlobalBounds().intersects(rect.getGlobalBounds()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
