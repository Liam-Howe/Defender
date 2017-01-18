#pragma once


#include "SFML\Graphics.hpp"
#include "AI.h"
#include "Astronaut.h"
#include "Bullet.h"
#include "Player.h"
class Abductor 

{

public : 
	Abductor(sf::Vector2f _pos,sf::Vector2f _vel,sf::Texture _tex,sf::Texture _bulletTexture);
	~Abductor();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f _tempPos);
	sf::Sprite getSprite();
	sf::Vector2f computeAlignment(std::vector<Abductor*> agents);
	sf::Vector2f computeCohesion(std::vector<Abductor*> agents);
	sf::Vector2f computeSeparation(std::vector<Abductor*> agents);
	void update();
	void seek(sf::Vector2f targetPos);
	sf::Vector2f Normalise(sf::Vector2f velocity);
	void movement(sf::Vector2f _playerPos);
	void wander(std::vector<Abductor*> agents);
	void abducting();
	void setAbducting(bool value);
	int getHealth();
	void takeDamage(int value);
	sf::Vector2f getVelocity();
	void setIndex(int value);
	std::vector<Bullet*>& getBullets();
	bool m_abducting;
	sf::RectangleShape getCollisionRect();
private : 
	std::vector<Bullet*> m_bullets;
	sf::RectangleShape collisionBox;
	sf::Vector2f m_pos;
	sf::Texture m_bulletTexture;
	sf::Vector2f m_vel;
	sf::Vector2f diff;
	sf::Vector2f steer;
	sf::Texture m_tex;
	sf::Sprite m_sprite;
	sf::Vector2f m_acceleration;
	float m_health;
	float maxSpeed;
	float maxForce;
	bool m_flock;
	bool m_seek;
	int index;
	int neighbourCount;
	float m_bulletTimer;
	sf::Vector2f v;
	sf::Vector2f pointToFlock;
	sf::Vector2f cohesion;
	sf::Vector2f separation;
	sf::Vector2f alignment;
	bool m_following;
	int health;
	sf::Vector2f m_generatedPos;
};