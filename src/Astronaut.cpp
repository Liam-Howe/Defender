
#include "../include/Astronaut.h"

Astronaut::Astronaut(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_Pos(_Pos), m_Vel(_Vel), m_Tex(_Tex)
{
	m_Sprite.setTexture(m_Tex);
	m_Sprite.setPosition(m_Pos);
	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);

	srand(time(NULL));

	generatedPos = rand() % 2048 + 1;
	m_fleeing = false;

	collisionBox =  sf::RectangleShape(sf::Vector2f(m_Sprite.getGlobalBounds().width, m_Sprite.getGlobalBounds().height));
	collisionBox.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);
	collisionBox.setPosition(m_Pos);
}

Astronaut::~Astronaut()
{

}

void Astronaut::movement(sf::Vector2f abductorPos)
{
	abductorDist = sqrt(((m_Pos.x - abductorPos.x) * (m_Pos.x - abductorPos.x)) + ((m_Pos.y - abductorPos.y) * (m_Pos.y - abductorPos.y)));

	if(abductorDist < 100)
	{
		m_fleeing = true;
	}
	 if (abductorDist > 300)
	{
		 m_fleeing = false;
	}

	 if (abductorDist < 300 && m_fleeing == true && m_Pos.y >= 690)
	 {
		 flee(abductorPos);
	 }
	 else if (m_fleeing == false && m_Pos.y >= 690)
	 {
		 wander();
	 }

	 if (m_abducted == true)
	 {
		 m_Pos.x = abductorPos.x;
		 m_Pos.y = abductorPos.y;
	 }

	 if (m_Pos.y < 690 && m_abducted == false)
	 {
		 m_Pos.y += 5;
	 }

	 m_Sprite.setPosition(m_Pos);
	 collisionBox.setPosition(m_Pos);
}
sf::RectangleShape Astronaut::getCollisionRect()
{
	return collisionBox;
}
void Astronaut::wander()
{
	m_Vel.x = generatedPos - m_Pos.x;
	m_Vel = Normalise(m_Vel);
	m_Vel.x = m_Vel.x / 5;
	m_Pos.x += m_Vel.x;
	m_Sprite.setPosition(m_Pos);
	collisionBox.setPosition(m_Pos);

	if (m_Pos.x == generatedPos)
	{
		m_Vel.x = 0;
		m_Pos.x = generatedPos + 10;
		generatedPos = rand() % 2048 + 1;
	}
}

void Astronaut::flee(sf::Vector2f abductorPos)
{
	m_Vel.x = m_Pos.x - abductorPos.x;
	m_Vel = Normalise(m_Vel);
	m_Vel.x = m_Vel.x / 5;
	m_Pos.x += m_Vel.x;
	m_Sprite.setPosition(m_Pos);
	collisionBox.setPosition(m_Pos);
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


