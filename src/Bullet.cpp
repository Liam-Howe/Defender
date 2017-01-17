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

	mutantFired = false;
	PI = 3.14159265;
	m_lifeTime = 0;
	collisionBox = sf::RectangleShape(sf::Vector2f(m_Sprite.getGlobalBounds().width, m_Sprite.getGlobalBounds().width));
	collisionBox.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);
	collisionBox.setPosition(m_pos);
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
	collisionBox.setPosition(m_pos);
	m_lifeTime += 1;
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

void Bullet::mutantUpdate(sf::Vector2f targetPos)
{
	if (mutantFired == false)
	{
		m_vel.x = targetPos.x - m_pos.x;
		m_vel.y = targetPos.y - m_pos.y;
		m_vel = Normalise(m_vel);
		m_pos += m_vel;
		m_Sprite.setPosition(m_pos);
		collisionBox.setPosition(m_pos);
		rotationVec = m_pos - targetPos;
		rotation = (atan2(rotationVec.y, rotationVec.x)) * 180 / PI;
		m_Sprite.setRotation(rotation);
		mutantFired = true;
	}
	else
	{
		m_pos.x = m_pos.x + m_vel.x;
		m_pos.y = m_pos.y + m_vel.y;
		m_Sprite.setPosition(m_pos);
		collisionBox.setPosition(m_pos);
	}
}

void Bullet::update()
{
	m_pos.x += m_speed;
	m_Sprite.setPosition(m_pos);
	collisionBox.setPosition(m_pos.x, m_pos.y);
	m_lifeTime += 1;
}

sf::Sprite Bullet::getSprite()
{
	return m_Sprite;
}
sf::RectangleShape Bullet::getCollisionRect()
{
	return collisionBox;
}

void Bullet::setLifetime(int value)
{
	m_lifeTime = value;
}

int Bullet::getLifeTime()
{
	return m_lifeTime;
}
