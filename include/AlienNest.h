#pragma once

#include "SFML\Graphics.hpp"
#include "AI.h"
#include "Bullet.h"

class AlienNest
{

public :
	AlienNest(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex);
	~AlienNest();
	
	sf::Sprite getSprite();
	sf::Vector2f getPosition();

	void update(sf::Vector2f playerPos, sf::Texture _alienMissile);

	std::vector<Bullet *> _nestBulletVector;

	void wander();
	void flee(sf::Vector2f playerPos);

	sf::Vector2f Normalise(sf::Vector2f velocity);

private:

	sf::Vector2f generatedPos;
	float playerDistance;

	int bulletTimer;
	int bulletCount;
	bool m_Afleeing;

	sf::Vector2f m_APos;
	sf::Vector2f m_AVel;
	sf::Texture m_ATex;
	sf::Sprite m_ASprite;

};
