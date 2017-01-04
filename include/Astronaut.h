#pragma once
#include "SFML\Graphics.hpp"

class Astronaut
{

public:

	Astronaut()
	~Astronaut();

	sf::Sprite getSprite();
	sf::Vector2f getPosition();

	void movement();
	void update();

private:

	sf::Vector2f m_AstroPos;
	sf::Vector2f m_AstroVel;
	sf::Vector2f m_AstroAccel;
	sf::Texture m_AstroTex;
	sf::Sprite m_AstroSprite;
	float randX;
	float randY;
};