#pragma once


#include "SFML\Graphics.hpp"
#include "AI.h"
#include "Astronaut.h"
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
	void movement(Astronaut& abductorPos);
	void wander();
	void abducting();
	void applyForce(sf::Vector2f force);
	void flock(std::vector<Abductor*>_abductor);
	 sf::Vector2f alignment(std::vector<Abductor*>_abductor);
	sf::Vector2f seperation(std::vector<Abductor*>_abductor);
	sf::Vector2f subTwoVector(sf::Vector2f,sf::Vector2f);
	sf::Vector2f divScalar(float,sf::Vector2f);
	sf::Vector2f addVector(sf::Vector2f,sf::Vector2f);
	sf::Vector2f getVelocity();
	sf::Vector2f mulScalar(float s, sf::Vector2f _currentVector);
	void run(std::vector<Abductor*>_abductors);
	sf::Vector2f limit(double max, sf::Vector2f _currentVector);
	sf::Vector2f cohesion(std::vector<Abductor*>_abductor);
	sf::Vector2f flockSeek(sf::Vector2f v);
	sf::Vector2f subVector(sf::Vector2f _pos, sf::Vector2f _currentVector);
	int getHealth();
	void takeDamage(int value);
	void setAbducting(bool value);
	bool getAbducting();
	sf::RectangleShape getCollisionRect();
private : 
	sf::RectangleShape collisionBox;
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	sf::Vector2f diff;
	sf::Vector2f steer;
	sf::Texture m_tex;
	sf::Sprite m_sprite;
	sf::Vector2f sum;
	sf::Vector2f m_acceleration;
	float m_health;
	bool m_abducting;
	float maxSpeed;
	float maxForce;
	bool m_flock;
	bool m_seek;
	bool m_following;
	int health;
	sf::Vector2f m_generatedPos;
};