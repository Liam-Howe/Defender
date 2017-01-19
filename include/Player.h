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
	void takeDamage(int value); //Decrements the players health by the recieved value
	int getBombCount(); //Gets if the player has a smart bomb ready
	void useBomb(); //Removes the availabe smart bomb
	void setCanHyperjump(bool value); //Sets whether or not the player can use the hyperjump ability
	bool getCanHyperJump(); //Checks whether or not the player can hyperjump
	void setMaxAcceleration(int value);//Sets how fast the player can move
	std::vector<Bullet*>& getBullets(); //Returns the players bullet vector
	void createBullet(sf::Texture,int ); //Creates a new bullet when the player fires
	bool getAlive(); //Checks if the player is still alive
	void setAlive(bool); //Sets the alive bool value
	bool getFastAccel(); //returns the players accleration under the effect of the speed power up
	void setFastAccel(bool); //Sets the players acceleration when the speed power up is active
	void hyperJump(); //Jumps the player to a new random location
	void setInvincible(bool value); //Sets whether or not the player is invincible according to a recieved value
	bool getInvincible(); //Checks if the player is invincible

private :
	std::vector<Bullet*> m_bullets; //Holds the players bullets
	sf::RectangleShape collisionBox; //Surrounds the player and is used for collisions 
	float m_friction; //Slows the player when not accelerating
	sf::Vector2f m_Pos; //Holds the players current position
	sf::Vector2f m_Vel; //Holds the players current velocity
	sf::Vector2f m_accel; //Holds the players current acceleration
	sf::Texture m_Tex; //Holds the players current texture
	sf::Sprite m_Sprite; //Holds the players current sprite
	int m_maxAcceleration; //The maximum value that the player can accelerate
	bool m_decelerate; //Starts the player decelerating
	bool m_direction; //Determines the direction the player is pointing
	bool m_canHyperJump; //Allows the player to hyperjump if true
	int health; //Holds the players current health
	int m_smartBombCount; //Holds the players smart bomb stock
	bool m_alive; //Determines if the player is currently alive
	bool m_fastAccel; //Determines if the player is under the effect of the speed power up
	float accelTimer; //Time limit for the speed power up
	bool invincible; //Determines if the player is invincible
	int invincibleTimer; //Time limit for the invincibility power up
};