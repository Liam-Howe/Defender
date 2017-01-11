#pragma once

#include "SFML\Graphics.hpp"
#include "AI.h"

class Mutant 
{

public:
	Mutant(sf::Vector2f _pos, sf::Vector2f _vel , sf::Texture _tex);
	~Mutant();

private:
	
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	sf::Sprite m_sprite;
	sf::Texture m_tex;
	float m_health;

};