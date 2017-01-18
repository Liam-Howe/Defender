#include "../include/AlienNest.h"
#include <iostream>

AlienNest::AlienNest(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_APos(_Pos), m_AVel(_Vel), m_ATex(_Tex)
{
	m_ASprite.setTexture(m_ATex);
	m_ASprite.setPosition(m_APos);
	m_ASprite.setOrigin(m_ASprite.getGlobalBounds().width / 2, m_ASprite.getGlobalBounds().height / 2);



	generatedPos.x = rand() % (5500 - 600 + 1) + 600;
	generatedPos.y = rand() % 400;

	bulletCount = 0;
	m_Afleeing = false;
	abductorSpawnTimer = 0;

	health = 2;

	collisionBox =  sf::RectangleShape(sf::Vector2f(m_ASprite.getGlobalBounds().width,m_ASprite.getGlobalBounds().width));
	collisionBox.setOrigin(m_ASprite.getGlobalBounds().width / 2, m_ASprite.getGlobalBounds().height / 2);
	collisionBox.setPosition(m_APos);
}

AlienNest::~AlienNest()
{

}

sf::Sprite AlienNest::getSprite()
{
	return m_ASprite;
}

sf::Vector2f AlienNest::getPosition()
{
	return m_APos;
}

void AlienNest::update(sf::Vector2f playerPos, sf::Texture _alienMissile)
{
	collisionBox.setPosition(m_APos.x, m_APos.y);
	playerDistance = sqrt(((m_APos.x - playerPos.x) * (m_APos.x - playerPos.x)) + ((m_APos.y - playerPos.y) * (m_APos.y - playerPos.y)));

	abductorSpawnTimer += 1;

	if (playerDistance < 150)
	{
		m_Afleeing = true;
	}
	if (playerDistance > 300)
	{
		m_Afleeing = false;
	}

	if (playerDistance < 300 && m_Afleeing == true)
	{
		flee(playerPos);

		if (bulletCount < 2)
		{
			bulletTimer += 1;

			if (bulletTimer > 100)
			{
				Bullet * _temp = new Bullet(sf::Vector2f(m_APos.x, m_APos.y), sf::Vector2f(0, 0), _alienMissile, 10);
				std::cout << "Missile Fired" << std::endl;
				_nestBulletVector.push_back(_temp);
				bulletTimer = 0;
				bulletCount++;
			}
		}
	}
	else if (m_Afleeing == false)
	{
		wander();
	}
}

void AlienNest::wander()
{
	m_AVel.x = generatedPos.x - m_APos.x;
	m_AVel.y = generatedPos.y - m_APos.y;
	m_AVel = Normalise(m_AVel);
	m_APos.x += m_AVel.x;
	m_APos.y += m_AVel.y;
	m_ASprite.setPosition(m_APos);

	if (m_APos == generatedPos)
	{
		m_AVel.x = 0;
		m_AVel.y = 0;
		m_APos.x = generatedPos.x + 10;
		generatedPos.x = rand() % 2048 + 1;
		generatedPos.y = rand() % 700 + 1;
	}
}

void AlienNest::flee(sf::Vector2f playerPos)
{
	m_AVel.x = m_APos.x - playerPos.x;
	m_AVel.y = m_APos.y - playerPos.y;
	m_AVel = Normalise(m_AVel);
	m_APos += m_AVel;
	m_ASprite.setPosition(m_APos);
}

sf::RectangleShape AlienNest::getCollisionRect()
{
	return collisionBox;
}

int AlienNest::getAbductorCount()
{
	return abductorCount;
}

void AlienNest::setAbductorCount(int value)
{
	abductorCount = value;
}

int AlienNest::getHealth()
{
	return health;
}

void AlienNest::takeDamage(int value)
{
	health = health - value;
}

std::vector<Bullet*>& AlienNest::getBullets()
{
	return _nestBulletVector;
}
sf::Vector2f AlienNest::Normalise(sf::Vector2f velocity)
{
	float length;
	length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = velocity / length;
	return velocity;
}
