#include "stdafx.h"
#include "AI.h"

AI::AI(sf::Vector2f m_AIpos, sf::Vector2f _Vel, sf::Texture _Tex) : m_Pos(_Pos), m_Vel(_Vel), m_Tex(_Tex)
{
	m_AIsprite.setTexture(m_Tex);
	m_AIsprite.setPosition(m_Pos);
	m_AIsprite.setOrigin(m_AIsprite.getGlobalBounds().width / 2, m_AIsprite.getGlobalBounds().height / 2);
	m_AIaccel = sf::Vector2f(0, 0);)
}

AI::~AI()
{
}
