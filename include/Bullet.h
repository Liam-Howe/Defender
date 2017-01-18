#pragma once

#include "SFML\Graphics.hpp"

class Bullet
{

public :
	sf::Sprite getSprite();
	void update();
	Bullet(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex, float _speed);
	~Bullet();
	void seekerUpdate(sf::Vector2f targetPos);
	void mutantUpdate(sf::Vector2f targetPos);
	sf::Vector2f Normalise(sf::Vector2f velocity);
	
	sf::RectangleShape getCollisionRect();
	void setLifetime(int value);
	int getLifeTime();
private:

	int m_lifeTime;
	sf::RectangleShape collisionBox;
	sf::Vector2f m_pos;
	sf::Vector2f m_vel;
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;
	float m_speed;
	float PI;
	float rotation;
	bool mutantFired;
	sf::Vector2f rotationVec;


};