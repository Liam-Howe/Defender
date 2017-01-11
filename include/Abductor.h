#pragma once


#include "SFML\Graphics.hpp"
#include "AI.h"
class Abductor 

{

public : 
	Abductor(sf::Vector2f _pos,sf::Vector2f _vel,sf::Texture _tex);
	~Abductor();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _tempPos);
	sf::Sprite getSprite();
	void update();
	void seek(sf::Vector2f targetPos);
	sf::Vector2f Normalise(sf::Vector2f velocity);
	void movement(sf::Vector2f abductorPos);

private : 
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	sf::Texture m_tex;
	sf::Sprite m_sprite;
	float m_health;
	bool m_flock;
	bool m_seek;

};