#pragma once
#include "SFML\Graphics.hpp"
#include "Astronaut.h"
class Astronaut
{

public:

	Astronaut(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex);
	~Astronaut();

	void movement(sf::Vector2f abductorPos);

	sf::Sprite getSprite();
	sf::Vector2f getPosition();

	sf::Vector2f Normalise(sf::Vector2f velocity);
	void update();

private:

	sf::Vector2f m_Pos;
	sf::Vector2f m_Vel;
	sf::Vector2f m_Velocity;
	sf::Texture m_Tex;
	sf::Sprite m_Sprite;
	float abductorDist;
	float generatedPos;
};