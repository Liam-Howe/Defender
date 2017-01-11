

#include "../include/Abductor.h"

Abductor::Abductor(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex) : m_pos(_pos) , m_vel(_vel),m_tex(_tex)
{
	m_sprite.setTexture(m_tex);
	m_sprite.setPosition(m_pos);
}
Abductor::~Abductor()
{

}
void Abductor::update()
{

}
void Abductor::movement(sf::Vector2f targetPos)
{
	float Dist = sqrt(((m_pos.x - targetPos.x) * (m_pos.x - targetPos.x)) + ((m_pos.y - targetPos.y) * (m_pos.y - targetPos.y)));

	if (Dist > 100)
	{
		m_seek = true;
	}
	if (Dist < 300)
	{
		m_seek = false;
	}
}

void Abductor::seek(sf::Vector2f targetPos)
{
	m_vel.x = targetPos.x - m_pos.x;
	m_vel.y = targetPos.y - m_pos.y;
	m_vel = Normalise(m_vel);
	m_pos += m_vel;
	m_sprite.setPosition(m_pos);

}
sf::Vector2f Abductor::Normalise(sf::Vector2f velocity)
{
	float length;
	length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = velocity / length;
	return velocity;
}
sf::Vector2f Abductor::getPosition()
{
	return m_pos;
}
void Abductor::setPosition(sf::Vector2f _tempPos)
{
	m_pos = _tempPos;
}

sf::Sprite Abductor::getSprite()
{
	return m_sprite;
}