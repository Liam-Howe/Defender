#pragma once

#include "SFML\Graphics.hpp"

class Bullet
{

public :
	sf::Sprite getSprite(); //returns the bullets current sprite
	void update(); //The update for the players bullets
	Bullet(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex, float _speed);
	~Bullet();
	void seekerUpdate(sf::Vector2f targetPos); //The update for seeker bullets
	void mutantUpdate(sf::Vector2f targetPos); //The update for mutant/abductor bullets
	sf::Vector2f Normalise(sf::Vector2f velocity); //Normalises vector passed into method
	
	sf::RectangleShape getCollisionRect(); //Returns collision box of the bullet
	void setLifetime(int value); //Sets how long the bullet can live
	int getLifeTime(); //Returns how long the bullet has left to live
private:

	int m_lifeTime; //Holds how long the bullet can live
	sf::RectangleShape collisionBox; //Creates a box around the bullet for collision
	sf::Vector2f m_pos; //Holds the bullets current position
	sf::Vector2f m_vel; //Holds the bullets current velocity
	sf::Sprite m_Sprite; //Holds the bullets current sprite
	sf::Texture m_Texture; //Holds the bullets current texture
	float m_speed; //Holds the speed of the bullet
	float PI; //Holds the value for PI
	float rotation; //Holds angle the bullet is fired at
	bool mutantFired; //Determines whether or not a mutant has fired
	sf::Vector2f rotationVec; //Holds a vector which allows the bullets direction to change to where a target is


};