#include "../include/AlienNest.h"


AlienNest::AlienNest(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_APos(_Pos), m_AVel(_Vel), m_ATex(_Tex)
{
	m_ASprite.setTexture(m_ATex);
	m_ASprite.setPosition(m_APos);
	m_ASprite.setOrigin(m_ASprite.getGlobalBounds().width / 2, m_ASprite.getGlobalBounds().height / 2);

	srand(time(NULL));

	generatedPos.x = rand() % 400;
	generatedPos.y = rand() % 400;
}

AlienNest::~AlienNest()
{

}

sf::Sprite AlienNest::getSprite()
{
	return sf::Sprite();
}

sf::Vector2f AlienNest::getPosition()
{
	return sf::Vector2f();
}

void AlienNest::update(sf::Vector2f playerPos, sf::Texture _alienMissile)
{
	playerDistance = sqrt((m_APos.x - playerPos.x) + (m_APos.y - playerPos.y));

	if (playerDistance < 20)
	{
		flee(playerPos);

		if (bulletCount < 2)
		{
			bulletTimer += 1;

			if (bulletTimer > 50)
			{
				Bullet * _temp = new Bullet(sf::Vector2f(m_APos.x, m_APos.y), sf::Vector2f(0, 1), _alienMissile, 10);
				_nestBulletVector.push_back(_temp);
				bulletTimer = 0;
				bulletCount++;
			}
		}
	}
	else
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

sf::Vector2f AlienNest::Normalise(sf::Vector2f velocity)
{
	float length;
	length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = velocity / length;
	return velocity;
}
