#pragma once
#include "SFML\Graphics.hpp"
class AI
{
public:
	AI();
	~AI();




	sf::Vector2f m_Pos;
	sf::Vector2f m_Vel;
	sf::Texture m_Tex;
	sf::Sprite m_Sprite;
	float m_health;
	

};

