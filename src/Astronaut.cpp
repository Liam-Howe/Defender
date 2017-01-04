
#include "../include/Astronaut.h"

Astronaut::Astronaut(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_Pos(_Pos), m_Vel(_Vel), m_Tex(_Tex)
{
	m_Sprite.setTexture(m_Tex);
	m_Sprite.setPosition(m_Pos);
	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);
}

Astronaut::~Astronaut()
{
}

void Astronaut::movement()
{
	//srand(time(NULL));

	//randX = rand_FloatRange(screenHeight);
	//randY = rand_FloatRange(screenHeight);

}

void Astronaut::update()
{

}

sf::sf::Vector2f Astronaut::getPosition()
{
	return m_AstroPos
}

sf::Sprite Astronaut::getSprite()
{
	return m_AstroSprite;
}


