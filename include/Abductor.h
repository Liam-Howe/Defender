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
	sf::Vector2f flock(Abductor& _abductor);
	 sf::Vector2f alignment(Abductor&_abductor);
	sf::Vector2f seperation(Abductor& _abductor);
	sf::Vector2f cohesion(Abductor _abductor);
	sf::Vector2f subTwoVector(sf::Vector2f,sf::Vector2f);
	sf::Vector2f Abductor::divScalar(float);
	sf::Vector2f addVector(sf::Vector2f);
	sf::Vector2f getVelocity();
	sf::Vector2f mulScalar(float s);
	sf::Vector2f sum;
	sf::Vector2f limit(double max);
	
	
private : 
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	sf::Vector2f diff;
	sf::Vector2f steer;
	sf::Texture m_tex;
	sf::Sprite m_sprite;
	float m_health;
	float maxSpeed;
	float maxForce;
	bool m_flock;
	bool m_seek;

};