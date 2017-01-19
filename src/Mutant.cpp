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
	m_neighourCount = 0;
	m_index = 0;
	m_pointToFlock = sf::Vector2f(0, 0);
	m_cohesion = sf::Vector2f(0, 0);
	m_seperation = sf::Vector2f(0, 0);
	m_alignment = sf::Vector2f(0, 0);
}

Mutant::~Mutant()
{

}
sf::Vector2f Mutant::getVelocity()
{
	return m_vel;
}
void Mutant::setindex(int value)
{
	m_index = value;
}
sf::Vector2f Mutant::computeAlignment(std::vector<Mutant*> agents)
{
	m_neighourCount = 0;
	v = sf::Vector2f(0, 0);

	for (int i = 0; i < agents.size(); i++)
	{
		if (i != m_index)
		{
			float agentDist = sqrt(((agents[i]->getPosition().x - m_pos.x) * (agents[i]->getPosition().x - m_pos.x)) + ((agents[i]->getPosition().y - m_pos.y) * (agents[i]->getPosition().y - m_pos.y)));

			if (agentDist < 300)
			{
				v.x += agents[i]->getVelocity().x;
				v.y += agents[i]->getVelocity().y;
				m_neighourCount++;
			}
		}
	}

	if (m_neighourCount == 0)
	{
		return v;
	}

	v.x = v.x / m_neighourCount;
	v.y = v.y / m_neighourCount;
	v = Normalise(v);
	m_alignment = v;
	return v;
}
sf::Vector2f Mutant::computeCohesion(std::vector<Mutant*> agents)
{
	m_neighourCount = 0;
	v = sf::Vector2f(0, 0);

	for (int i = 0; i < agents.size(); i++)
	{
		if (i != m_index)
		{
			float agentDist = sqrt(((agents[i]->getPosition().x - m_pos.x) * (agents[i]->getPosition().x - m_pos.x)) + ((agents[i]->getPosition().y - m_pos.y) * (agents[i]->getPosition().y - m_pos.y)));

			if (agentDist < 300 && agentDist > 30)
			{
				v.x += agents[i]->getPosition().x;
				v.y += agents[i]->getPosition().y;
				m_neighourCount++;
			}
		}
	}

	if (m_neighourCount == 0)
	{
		return v;
	}

	v.x = v.x / m_neighourCount;
	v.y = v.y / m_neighourCount;
	sf::Vector2f v2 = sf::Vector2f(v.x - m_pos.x, v.y - m_pos.y);
	v = Normalise(v2);
	m_cohesion = v;
	return v;
}

sf::Vector2f Mutant::computeSeparation(std::vector<Mutant*> agents)
{
	m_neighourCount = 0;
	v = sf::Vector2f(0, 0);

	for (int i = 0; i < agents.size(); i++)
	{
		if (i != m_index)
		{
			float agentDist = sqrt(((agents[i]->getPosition().x - m_pos.x) * (agents[i]->getPosition().x - m_pos.x)) + ((agents[i]->getPosition().y - m_pos.y) * (agents[i]->getPosition().y - m_pos.y)));

			if (agentDist < 30)
			{
				v.x += agents[i]->getPosition().x - m_pos.x;
				v.y += agents[i]->getPosition().y - m_pos.y;
				m_neighourCount++;
			}
		}
	}

	if (m_neighourCount == 0)
	{
		return v;
	}
	v.x /= m_neighourCount;
	v.y /= m_neighourCount;

	v.x *= -1;
	v.y *= -1;

	v = Normalise(v);
	m_seperation = v;
	return v;
}

sf::Vector2f Mutant::Normalise(sf::Vector2f velocity)
{
	float length;
	length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	if (length != 0)
	{
		velocity = velocity / length;
		return velocity;
	}
	else
	{
		return sf::Vector2f(0, 0);
	}
}

void Mutant::swarm(std::vector<Mutant*> agents, sf::Vector2f _playerPos)
{

	if (v != sf::Vector2f(0, 0))
	{
		m_pointToFlock = _playerPos - m_pos;
		m_pointToFlock = Normalise(m_pointToFlock);

		m_vel.x += (m_alignment.x + m_cohesion.x + m_seperation.x) + m_pointToFlock.x;
		m_vel.y += (m_alignment.y + m_cohesion.y + m_seperation.y) + m_pointToFlock.y;

		m_vel = Normalise(m_vel);

		m_vel.x = m_vel.x * 0.75;
		m_vel.y = m_vel.y * 0.75;

		m_pos += m_vel;


		float dist = sqrt(((m_pos.x - m_generatedPos.x) * (m_pos.x - m_generatedPos.x)) + (m_pos.y - m_generatedPos.y) * (m_pos.y - m_generatedPos.y));

		if (dist < 200)
		{
			m_seek = false;
		}

	}
	else
	{
		m_seek =true;
	}
	m_sprite.setPosition(m_pos);
	collisionBox.setPosition(m_pos);
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

void Mutant::movement(sf::Vector2f targetPos, sf::Texture _playerBullet)
{
	float Dist = sqrt(((m_pos.x - targetPos.x) * (m_pos.x - targetPos.x)) + ((m_pos.y - targetPos.y) * (m_pos.y - targetPos.y)));


	if (Dist < 200)
	{
		m_seek = false;
	}

	if (m_seek == true)
	{
		seek(targetPos);
	}

	if (m_seek == false)
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



int Mutant::getHealth()
{
	return health;
}

void Mutant::takeDamage(int value)
{
	health = health - value;
}

std::vector<Bullet*>& Mutant::getBullets()
{
	return _mutantBulletVector;
}
