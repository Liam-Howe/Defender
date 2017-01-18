#pragma once

#include "SFML\Graphics.hpp"
#include "AI.h"
#include "Bullet.h"

class Mutant 
{

public:
	Mutant(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex);
	~Mutant();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _tempPos);
	sf::Sprite getSprite();
	sf::RectangleShape getCollisionRect();
	void update();
	void seek(sf::Vector2f targetPos);
	sf::Vector2f Normalise(sf::Vector2f velocity);
	void movement(sf::Vector2f targetPos, sf::Texture _playerBullet);
	void fire(sf::Vector2f targetPos, sf::Texture _playerBullet);
	void swarm();
	int getHealth();
	void takeDamage(int value);
	std::vector<Bullet*>& getBullets();

private:
	std::vector<Bullet*> _mutantBulletVector;
	sf::RectangleShape collisionBox;
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	sf::Texture m_tex;
	sf::Sprite m_sprite;
	float bulletTimer;
	bool m_seek;
	bool m_following;
	int health;
};