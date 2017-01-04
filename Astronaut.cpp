#include "stdafx.h"
#include "Astronaut.h"

Astronaut::Astronaut(sf::Vector2f m_pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_Pos(_Pos), m_Vel(_Vel), m_Tex(_Tex)
{
	m_AstroSprite.setTexture(m_Tex);
	m_AstroSprite.setPosition(m_Pos);
	m_AstroSprite.setOrigin(m_AstroSprite.getGlobalBounds().width / 2, m_AstroSprite.getGlobalBounds().height / 2);
	m_AstroAccel = sf::Vector2f(0, 0);)
}

Astronaut::~Astronaut()
{
}

void Astronaut::movement()
{

}

sf::Sprite Astronaut::getSprite()
{
	return m_Sprite;
}


