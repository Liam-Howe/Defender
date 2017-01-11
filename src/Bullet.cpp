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

	PI = 3.14159265;
	lifeTime = 0;
}

Bullet::~Bullet()
{

}

void Bullet::seekerUpdate(sf::Vector2f targetPos)
{
	m_vel.x = targetPos.x - m_pos.x;
	m_vel.y = targetPos.y - m_pos.y;
	m_vel = Normalise(m_vel);
	m_pos += m_vel;
	m_Sprite.setPosition(m_pos);
	lifeTime += 1;
	rotationVec = m_pos - targetPos;
	rotation = (atan2(rotationVec.y, rotationVec.x)) * 180 / PI;

	m_Sprite.setRotation(rotation);
}

sf::Vector2f Bullet::Normalise(sf::Vector2f velocity)
{
	float length;
	length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = velocity / length;
	return velocity;
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