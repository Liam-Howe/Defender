#pragma once
#include "SFML\Graphics.hpp"
class Player {

public : 

	Player(sf::Vector2f m_Pos,sf::Vector2f _Vel,sf::Texture _Tex);
	~Player();
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	void move(sf::Vector2f speed);
	void setPosition(sf::Vector2f _tempPos);
	void update();
	bool  isdecelerating();
	void setdecelerating(bool value);
private :

	sf::Vector2f m_Pos;
	sf::Vector2f m_Vel;
	sf::Vector2f m_accel;
	sf::Texture m_Tex;
	sf::Sprite m_Sprite;
	bool m_decelerate;
};