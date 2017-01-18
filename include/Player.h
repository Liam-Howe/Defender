#pragma once
#include <iostream>
#include "SFML\Graphics.hpp"
#include <string>
#include "Bullet.h"
class Player {

public : 

	Player(sf::Vector2f m_Pos,sf::Vector2f _Vel,sf::Texture _Tex);
	~Player();
	sf::Sprite getSprite(); //Returns the Player Sprite 
	sf::Vector2f getPosition(); //Returns the Player Position
	void move(sf::Vector2f speed, float _dt); //Moves the player object
	void setPosition(sf::Vector2f _tempPos); //Sets the player position to the recieved position
	void update(float _dt); //Players update loop
	bool  isdecelerating(); //Checks if the player is currently decelerating or not
	void setdecelerating(bool value); //Sets the players decelerating bool
	void setdirection(bool value); //Sets the direction the player is facing
	bool getDirection(); //Gets the direction the player is facing
	void handleInput(float); //Handles key presses for control of the player
	void spawn(sf::Vector2f _newPos);// Spawns the player at a new position
	sf::RectangleShape getCollisionRect(); //Returns the collision box for the player
	int getHealth(); //Returns the value of the players health
	void takeDamage(int value);
	int getBombCount();
	void useBomb();
	void setCanHyperjump(bool value);
	bool getCanHyperJump();
	void setMaxAcceleration(int value);
	std::vector<Bullet*>& getBullets();
	void createBullet(sf::Texture,int );
	bool getAlive();
	void setAlive(bool);
	bool getFastAccel();
	void setFastAccel(bool);
	void hyperJump();
	void setInvincible(bool value);
	bool getInvincible();

private :
	std::vector<Bullet*> m_bullets;
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
	bool m_alive;
	bool m_fastAccel;
	float accelTimer;
	bool invincible;
	int invincibleTimer;
};