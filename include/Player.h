#pragma once
#include "SFML\Graphics.hpp"
class Player {

public : 

	Player(sf::Vector2f m_Pos,sf::Vector2f _Vel,sf::Texture _Tex);
	~Player();
	sf::Sprite getSprite();
	void move(sf::Vector2f speed);
private :

	sf::Vector2f m_Pos;
	sf::Vector2f m_Vel;
	sf::Vector2f m_accel;
	sf::Texture m_Tex;
	sf::Sprite m_Sprite;
};