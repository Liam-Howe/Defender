#include "../include/PowerUp.h"


PowerUp::PowerUp(sf::Vector2f _pos, sf::Texture _tex , PowerUPType _type) : m_pos(_pos) , m_tex(_tex), m_type(_type)
{

	m_Sprite.setPosition(m_pos);
	m_Sprite.setTexture(m_tex);
	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);
	m_active = false;
	m_collisionRect = sf::RectangleShape(sf::Vector2f(m_Sprite.getGlobalBounds().width, m_Sprite.getGlobalBounds().width));
	m_collisionRect.setPosition(m_pos);
}

void PowerUp::update()
{

	m_Sprite.setPosition(m_pos);
	m_collisionRect.setPosition(m_pos);
}
PowerUp::~PowerUp()
{


}
sf::Sprite PowerUp::getSprite()
{
	return m_Sprite;
}
sf::RectangleShape PowerUp::getCollisionRect()
{
	return m_collisionRect;
}
PowerUPType PowerUp::getType()
{
	return m_type;
}