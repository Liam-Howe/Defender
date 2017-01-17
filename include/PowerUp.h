#pragma once
#include <SFML/Graphics.hpp>
#include "PowerUpType.h"
class PowerUp
{
public:
	
	PowerUp(sf::Vector2f,sf::Texture, PowerUPType);
	~PowerUp();
	sf::Sprite getSprite();
	void update();
	sf::RectangleShape getCollisionRect();
	PowerUPType getType();
private:
	sf::Vector2f m_pos;
	float m_ttl;
	sf::Texture m_tex;
	sf::Sprite m_Sprite;
	bool m_active;
	PowerUPType m_type;
	sf::RectangleShape m_collisionRect;
};