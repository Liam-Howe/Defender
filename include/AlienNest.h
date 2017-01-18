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

	

	void wander();
	void flee(sf::Vector2f playerPos);
	int bulletCount;
	int abductorSpawnTimer;

	sf::Vector2f Normalise(sf::Vector2f velocity);
	sf::RectangleShape getCollisionRect();
	sf::RectangleShape collisionBox;

	int getAbductorCount();
	void setAbductorCount(int value);

	int getHealth();
	void takeDamage(int value);
	std::vector<Bullet*>& getBullets();
private:
	std::vector<Bullet *> _nestBulletVector;
	sf::Vector2f generatedPos;
	float playerDistance;

	int bulletTimer;
	bool m_Afleeing;

	sf::Vector2f m_APos;
	sf::Vector2f m_AVel;
	sf::Texture m_ATex;
	sf::Sprite m_ASprite;
	int abductorCount;

	int health;

};
