#include "../include/Mutant.h"
#include <iostream>

Mutant::Mutant(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex) : m_pos(_pos), m_vel(_vel), m_tex(_tex)
{
	m_sprite.setTexture(m_tex);
	m_sprite.setPosition(m_pos);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);

	bulletTimer = 0;
	m_seek = false;

	health = 1;

	collisionBox.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
	collisionBox = sf::RectangleShape(sf::Vector2f(m_tex.getSize().x, m_tex.getSize().y));
	collisionBox.setPosition(m_pos.x, m_pos.y);
}

Mutant::~Mutant()
{

}

sf::Vector2f Mutant::getPosition()
{
	return m_pos;
}

void Mutant::setPosition(sf::Vector2f _tempPos)
{
	m_pos.x = _tempPos.x;
	m_pos.y = _tempPos.y;
}

sf::Sprite Mutant::getSprite()
{
	return m_sprite;
}

sf::RectangleShape Mutant::getCollisionRect()
{
	return collisionBox;
}

void Mutant::update()
{

}

void Mutant::seek(sf::Vector2f targetPos)
{
	m_vel.x = targetPos.x - m_pos.x;
	m_vel.y = targetPos.y - m_pos.y;
	m_vel = Normalise(m_vel);
	m_pos += m_vel;
	m_sprite.setPosition(m_pos);
	collisionBox.setPosition(m_pos.x, m_pos.y);
}

sf::Vector2f Mutant::Normalise(sf::Vector2f velocity)
{
	float length;
	length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = velocity / length;
	return velocity;
}

void Mutant::movement(sf::Vector2f targetPos, sf::Texture _playerBullet)
{
	float Dist = sqrt(((m_pos.x - targetPos.x) * (m_pos.x - targetPos.x)) + ((m_pos.y - targetPos.y) * (m_pos.y - targetPos.y)));

	if (Dist > 200)
	{
		m_seek = true;
	}

	else if (Dist < 300)
	{
		m_seek = false;
	}

	if (m_seek == true)
	{
		seek(targetPos);
	}

	else if (m_seek == false)
	{
		bulletTimer += 1;
	}

	if (bulletTimer >= 150)
	{
		fire(targetPos, _playerBullet);
		bulletTimer = 0;
	}
}

void Mutant::fire(sf::Vector2f targetPos, sf::Texture _playerBullet)
{
	Bullet * _temp = new Bullet(sf::Vector2f(m_pos.x + (m_tex.getSize().x/2), m_pos.y + (m_tex.getSize().y/2)), sf::Vector2f(0, 0), _playerBullet, 10);
	std::cout << "Mutant Fired" << std::endl;
	_mutantBulletVector.push_back(_temp);
}

void Mutant::swarm()
{

}

int Mutant::getHealth()
{
	return health;
}

void Mutant::takeDamage(int value)
{
	health = health - value;
}

std::vector<Bullet*> Mutant::getBullets()
{
	return _mutantBulletVector;
}
