#pragma once
#include "SFML\Graphics.hpp"
class Player {

public : 

	Player(sf::Vector2f m_Pos,sf::Vector2f _Vel,sf::Texture _Tex,sf::Sprite _Sprite);
	~Player();


private :

	sf::Vector2f m_Pos;
	sf::Vector2f m_Vel;
	sf::Texture m_Tex;
	sf::Sprite m_Sprite;

};