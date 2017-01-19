#pragma once
#include <SFML/Graphics.hpp>
#include "PowerUpType.h"
class PowerUp
{
public:
	
	PowerUp(sf::Vector2f,sf::Texture, PowerUPType);//constructs the powe up object
	~PowerUp();
	sf::Sprite getSprite();//returns the [ower up sprite
	void update();//updates power up lifetime
	sf::RectangleShape getCollisionRect();//returns the power ups collision rectangle
	PowerUPType getType();//returns the pwoer up type
private:
	sf::Vector2f m_pos;//position of the power up
	float m_ttl;// time to live for the power up
	sf::Texture m_tex;//texture for the power up
	sf::Sprite m_Sprite;//sprite for the power up

	PowerUPType m_type;//type of pwoer up
	sf::RectangleShape m_collisionRect;//collision rectangle for the power up
};