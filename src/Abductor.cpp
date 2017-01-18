

#include "../include/Abductor.h"

Abductor::Abductor(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex, sf::Texture _bulletTexture) : m_pos(_pos) , m_vel(_vel),m_tex(_tex),m_bulletTexture(_bulletTexture)
{
	m_sprite.setTexture(m_tex);
	m_sprite.setPosition(m_pos);
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
	maxSpeed = 3.5;
	maxForce = 0.5;
	m_vel = sf::Vector2f(rand() % 3 - 2, rand() % 3 - 2);
	m_abducting = false;
	health = 1;

	collisionBox =  sf::RectangleShape(sf::Vector2f(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().width));
	collisionBox.setOrigin(m_sprite.getGlobalBounds().width / 2, m_sprite.getGlobalBounds().height / 2);
	collisionBox.setPosition(m_pos);
	m_generatedPos.x = rand() % (5500 - 600 + 1) + 600;
	m_generatedPos.y = rand() % (600 - 100 + 1) + 100;
}
Abductor::~Abductor()
{

}

sf::Vector2f Abductor::computeAlignment(std::vector<Abductor*> agents)
{
	v = sf::Vector2f(0, 0);
	for (int i = 0; i < agents.size(); i++)
	{
		if (i != index)
		{
			float agentDist = sqrt(((agents[i]->getPosition().x - m_pos.x) * (agents[i]->getPosition().x - m_pos.x)) + ((agents[i]->getPosition().y - m_pos.y) * (agents[i]->getPosition().y - m_pos.y)));

			if (agentDist < 250)
			{
				v.x += agents[i]->getVelocity().x;
				v.y += agents[i]->getVelocity().y;
				neighbourCount++;
			}
		}
	}

	if (neighbourCount == 0)
	{
		return v;
	}

	v.x = v.x / neighbourCount;
	v.y = v.y / neighbourCount;
	v = Normalise(v);
	return v;
}
sf::Vector2f Abductor::computeCohesion(std::vector<Abductor*> agents)
{
	v = sf::Vector2f(0, 0);
	for (int i = 0; i < agents.size(); i++)
	{
		if (i != index)
		{
			float agentDist = sqrt(((agents[i]->getPosition().x - m_pos.x) * (agents[i]->getPosition().x - m_pos.x)) + ((agents[i]->getPosition().y - m_pos.y) * (agents[i]->getPosition().y - m_pos.y)));

			if (agentDist < 150 && agentDist > 70)
			{
				v.x += agents[i]->getPosition().x;
				v.y += agents[i]->getPosition().y;
				//neighbourCount++;
			}
		}
	}

	if (neighbourCount == 0)
	{
		return v;
	}

	v.x = v.x / neighbourCount;
	v.y = v.y / neighbourCount;
	sf::Vector2f v2 = sf::Vector2f(v.x - m_pos.x, v.y - m_pos.y);
	v = Normalise(v2);
	return v;
}
sf::Vector2f Abductor::computeSeparation(std::vector<Abductor*> agents)
{
	v = sf::Vector2f(0, 0);

	for (int i = 0; i < agents.size(); i++)
	{
		if (i != index)
		{
			float agentDist = sqrt(((agents[i]->getPosition().x - m_pos.x) * (agents[i]->getPosition().x - m_pos.x)) + ((agents[i]->getPosition().y - m_pos.y) * (agents[i]->getPosition().y - m_pos.y)));

			if (agentDist < 100)
			{
				v.x += agents[i]->getPosition().x - m_pos.x;
				v.y += agents[i]->getPosition().y - m_pos.y;
				//neighbourCount++;
			}
		}
	}

	if (neighbourCount == 0)
	{
		return v;
	}
	v.x /= neighbourCount;
	v.y /= neighbourCount;

	v.x *= -2;
	v.y *= -2;

	v = Normalise(v);
	return v;
}


void Abductor::update()
{
	m_sprite.setPosition(m_pos);
	collisionBox.setPosition(m_pos.x, m_pos.y);
}
void Abductor::setAbducting(bool value)
{
	m_abducting = value;
}

sf::Vector2f Abductor::getVelocity()
{
	return m_vel;
}
void Abductor::setIndex(int value)
{
	index = value;
}
std::vector<Bullet*>& Abductor::getBullets()
{
	return m_bullets;
}
void Abductor::movement(sf::Vector2f _playerPos)
{
	float Dist = sqrt(((m_pos.x - _playerPos.x) * (m_pos.x - _playerPos.x)) + ((m_pos.y - _playerPos.y) * (m_pos.y - _playerPos.y)));

	if (Dist < 300)
	{
		m_bulletTimer += 1;
	}


	if (m_bulletTimer >= 300)
	{
		Bullet * _temp = new Bullet(sf::Vector2f(m_pos.x + (m_tex.getSize().x / 2), m_pos.y + (m_tex.getSize().y / 2)), sf::Vector2f(0, 0), m_bulletTexture, 10);
		m_bullets.push_back(_temp);
		m_bulletTimer = 0;
	}
}
void Abductor::abducting()
{
	m_abducting = true;
	m_pos.y -= 0.5f;
	m_sprite.setPosition(m_pos);
	collisionBox.setPosition(m_pos);
}

void Abductor::wander(std::vector<Abductor*> agents)
{
	
	pointToFlock = m_generatedPos - m_pos;
	pointToFlock = Normalise(pointToFlock);

	alignment = computeAlignment(agents);
	/*if (neighbourCount != 0)
	{*/
		cohesion = computeCohesion(agents);
		separation = computeSeparation(agents);

		m_vel.x += (alignment.x + cohesion.x + separation.x) + pointToFlock.x;
		m_vel.y += (alignment.y + cohesion.y + separation.y) + pointToFlock.y;

		m_vel = Normalise(m_vel);

		m_vel.x = m_vel.x * 0.2;
		m_vel.y = m_vel.y * 0.2;

		m_pos += m_vel;
		m_sprite.setPosition(m_pos);
	//}
	/*else if (neighbourCount ==0)
	{
		m_vel.x = m_generatedPos.x - m_pos.x;
		m_vel.y = m_generatedPos.y - m_pos.y;
		m_vel = Normalise(m_vel);
		m_pos.x += m_vel.x;
		m_pos.y += m_vel.y;
		m_sprite.setPosition(m_pos);

		if (m_pos == m_generatedPos)
		{
			m_vel.x = 0;
			m_vel.y = 0;
			m_pos.x = m_generatedPos.x + 10;
			m_generatedPos.x = rand() % 2048 + 1;
			m_generatedPos.y = rand() % 700 + 1;
		}
	}*/
	
	

	float Dist = sqrt(((m_pos.x - m_generatedPos.x) * (m_pos.x - m_generatedPos.x)) + ((m_pos.y - m_generatedPos.y) * (m_pos.y - m_generatedPos.y)));
	if (Dist< 10)
	{
		//m_vel.x = 0;
		//	m_vel.y = 0;
		m_pos.x = m_generatedPos.x + 10;
		m_generatedPos.x = rand() % (5500 - 60 + 1) + 600;
		m_generatedPos.y = rand() % (600 - 100 + 1) + 100;
	}
	collisionBox.setPosition(m_pos);
}

int Abductor::getHealth()
{
	return health;
}

void Abductor::takeDamage(int value)
{
	health = health - value;
}

sf::RectangleShape Abductor::getCollisionRect()
{
	return collisionBox;
}

void Abductor::seek(sf::Vector2f targetPos)
{
	m_vel.x = targetPos.x - m_pos.x;
	m_vel.y = targetPos.y - m_pos.y;
	m_vel = Normalise(m_vel);
	m_pos += m_vel *1.5f;
	m_sprite.setPosition(m_pos);
	collisionBox.setPosition(m_pos);
}
sf::Vector2f Abductor::Normalise(sf::Vector2f velocity)
{
	float length;
	length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	if (length !=0)
	{
		velocity = velocity / length;
		return velocity;
	}
	else
	{
		return sf::Vector2f(0,0);
	}

	//return velocity;
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