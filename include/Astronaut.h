#pragma once
#include "SFML\Graphics.hpp"
#include "Astronaut.h"
class Astronaut
{

public:

	Astronaut(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex);
	~Astronaut();

	sf::Sprite getSprite();
	sf::Vector2f getPosition();

	

	void movement();
	void update();

private:

	sf::Vector2f m_Pos;
	sf::Vector2f m_Vel;
	sf::Texture m_Tex;
	sf::Sprite m_Sprite;
	float randX;
	float randY;
};