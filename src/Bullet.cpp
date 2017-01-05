#include "../include/Bullet.h"


Bullet::Bullet(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex, float _speed) 
	: m_pos(_pos) ,
	m_vel(_vel) ,
	m_Texture(_tex)
{
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setPosition(m_pos);
	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);
	m_speed = _speed;

}

Bullet::~Bullet()
{


}

void Bullet::update()
{
	m_pos.x += m_speed;
	m_Sprite.setPosition(m_pos);
}

sf::Sprite Bullet::getSprite()
{
	return m_Sprite;
}