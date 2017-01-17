#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include <string>
class Player {

public : 

	Player(sf::Vector2f m_Pos,sf::Vector2f _Vel,sf::Texture _Tex);
	~Player();
	sf::Sprite getSprite();
	sf::Vector2f getPosition();
	void move(sf::Vector2f speed, float _dt);
	void setPosition(sf::Vector2f _tempPos);
	void update(float _dt);
	bool  isdecelerating();
	void setdecelerating(bool value);
	void setdirection(bool value);
	bool getDirection();
	void handleInput(float);
	void spawn(sf::Vector2f _newPos);
	sf::RectangleShape getCollisionRect();
	int getHealth();
	void takeDamage(int value);
	int getBombCount();
	void useBomb();
	void setCanHyperjump(bool value);
	void setMaxAcceleration(int value);

private :
	sf::RectangleShape collisionBox;
	float m_friction;
	sf::Vector2f m_Pos;
	sf::Vector2f m_Vel;
	sf::Vector2f m_accel;
	sf::Texture m_Tex;
	sf::Sprite m_Sprite;
	int m_maxAcceleration;
	bool m_decelerate;
	bool m_direction;
	bool m_canHyperJump;
	int health;
	int m_smartBombCount;
};