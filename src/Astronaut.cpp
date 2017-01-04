
#include "../include/Astronaut.h"

Astronaut::Astronaut(sf::Vector2f m_pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_Pos(_Pos), m_Vel(_Vel), m_Tex(_Tex)
{
	m_AstroSprite.setTexture(m_AstroTex);
	m_AstroSprite.setPosition(m_AstroPos);
	m_AstroSprite.setOrigin(m_AstroSprite.getGlobalBounds().width / 2, m_AstroSprite.getGlobalBounds().height / 2);
	m_AstroAccel = sf::Vector2f(0, 0);
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

sf::sf::Vector2f Astronaut::getPosition()
{
	return m_AstroPos
}

sf::Sprite Astronaut::getSprite()
{
	return m_AstroSprite;
}


