#pragma once
#include "SFML\Graphics.hpp"

class AI
{

public:

	AI(sf::Vector2f m_AIpos, sf::Vector2f m_AIvel, sf::Texture m_AItex);
	~AI();

private:

	sf::Vector2f m_AIpos;
	sf::Vector2f m_AIvel;
	sf::Vector2f m_AIaccel;
	sf::Texture m_AItex;
	sf::Sprite m_AIsprite;

};

