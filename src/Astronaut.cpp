
#include "../include/Astronaut.h"

Astronaut::Astronaut(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_Pos(_Pos), m_Vel(_Vel), m_Tex(_Tex)
{
	m_Sprite.setTexture(m_Tex);
	m_Sprite.setPosition(m_Pos);
	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);


	float _x = rand() % (5500 - 400 + 1) + 400;
	generatedPos = _x;
	m_fleeing = false;
	m_followed = false;
	m_abducted = false;
	collisionBox =  sf::RectangleShape(sf::Vector2f(m_Sprite.getGlobalBounds().width, m_Sprite.getGlobalBounds().height));
	collisionBox.setPosition(m_Pos.x, m_Pos.y);
	m_groundHeight = 690;
}

Astronaut::~Astronaut()
{

}

void Astronaut::movement(sf::Vector2f abductorPos)
{
	abductorDist = sqrt(((m_Pos.x - abductorPos.x) * (m_Pos.x - abductorPos.x)) + ((m_Pos.y - abductorPos.y) * (m_Pos.y - abductorPos.y)));

	if(abductorDist < 200)
	{
		m_fleeing = true;
	}
	if (abductorDist > 500)
	{
		 m_fleeing = false;
	}

	 if (m_fleeing)
	 {
		 flee(abductorPos);
	 }
	  if (m_fleeing == false)
	 {
		 wander();
	 }

	

	 if (m_Pos.y < m_groundHeight && m_abducted == false)
	 {
		 m_Pos.y += 5;
	 }

	 m_Sprite.setPosition(m_Pos);
	 collisionBox.setPosition(m_Pos.x, m_Pos.y);
}

void Astronaut::abducted(sf::Vector2f abductorPos)
{
		m_abducted = true;
		m_Pos.x = abductorPos.x;
		m_Pos.y = abductorPos.y;
		m_Sprite.setPosition(m_Pos);
		collisionBox.setPosition(m_Pos.x, m_Pos.y);
}


sf::RectangleShape Astronaut::getCollisionRect()
{
	return collisionBox;
}
bool Astronaut::getFollowed()
{
	return m_followed;
}
bool Astronaut::getAbducted()
{
	return m_abducted;
}
void Astronaut::setFollowed(bool value)
{
	m_followed = value;
}
void Astronaut::wander()
{
	m_Vel.x = generatedPos - m_Pos.x;
	m_Vel = Normalise(m_Vel);
	m_Vel.x = m_Vel.x / 5;
	m_Pos.x += m_Vel.x;
	m_Sprite.setPosition(m_Pos);
	

	if (m_Pos.x == generatedPos)
	{
		m_Vel.x = 0;
		m_Pos.x = generatedPos + 10;
		generatedPos =  rand() % (5500 - 400 + 1) + 400;
	}
}

void Astronaut::flee(sf::Vector2f abductorPos)
{
	m_Vel.x = m_Pos.x - abductorPos.x;
	m_Vel = Normalise(m_Vel);
	m_Vel.x = m_Vel.x / 5;
	m_Pos.x += m_Vel.x;
	m_Sprite.setPosition(m_Pos);
	
}

void Astronaut::setAbducted(bool value)
{
	m_abducted = value;
}


sf::Vector2f Astronaut::Normalise(sf::Vector2f velocity)
{
	float length;
	length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = velocity / length;
	return velocity;
}

void Astronaut::update()
{
	m_Sprite.setPosition(m_Pos);
	collisionBox.setPosition(m_Pos.x, m_Pos.y);
}

sf::Vector2f Astronaut::getPosition()
{
	return m_Pos;
}

sf::Sprite Astronaut::getSprite()
{
	return m_Sprite;
}


