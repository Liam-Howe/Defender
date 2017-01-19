#pragma once


#include "SFML\Graphics.hpp"
#include "Astronaut.h"
#include "Bullet.h"
#include "Player.h"
class Abductor 

{

public : 
	Abductor(sf::Vector2f _pos,sf::Vector2f _vel,sf::Texture _tex,sf::Texture _bulletTexture);
	~Abductor();
	sf::Vector2f getPosition(); //Returns the current positon for the abductor
	void setPosition(sf::Vector2f _tempPos); //Sets the abductors position to a recieved position
	sf::Sprite getSprite(); //Returns the abductors sprite
	sf::Vector2f computeAlignment(std::vector<Abductor*> agents); //Gets an alignment vector for an abductor flock
	sf::Vector2f computeCohesion(std::vector<Abductor*> agents); //Gets a cohesion vector for an abductor flock
	sf::Vector2f computeSeparation(std::vector<Abductor*> agents); //Gets a separation vector for an abductor flock
	void update(); //The abductors update loop
	void seek(sf::Vector2f targetPos); //Allows the abductor to seek towards a target position
	sf::Vector2f Normalise(sf::Vector2f velocity); //Normalises vector passed into method
	void movement(sf::Vector2f _playerPos); //Determines logic for abductor moving/firing
	void wander(std::vector<Abductor*> agents); //Sets behaviour for wandering/flocking
	void abducting(); //Tells thwe abductor what to do if they are abducting a target
	void setAbducting(bool value); //Seths whether or not the abductor is currently abducting a target
	int getHealth(); //Returns the abductors health
	void takeDamage(int value); //Decrements the abductors health
	sf::Vector2f getVelocity(); //Returns the abductors current velocity
	void setIndex(int value); //Sets the abductors current index to a recieved value
	std::vector<Bullet*>& getBullets(); //Returns the list of bullets for the abductor

	sf::RectangleShape getCollisionRect(); //Returns the collision box for the abductor
private : 
	std::vector<Bullet*> m_bullets; //Holds all the abductors current bullets
	sf::RectangleShape collisionBox; //Creates a box around the abductors current position for collisions
	sf::Vector2f m_pos; //Holds the abductors current position
	sf::Texture m_bulletTexture; //Holds the texture for the abductors bullets
	sf::Vector2f m_vel; //Holds the abductors current velocity
	sf::Texture m_tex; //Holds the abductors current texture
	sf::Sprite m_sprite; //Holds the abductors current sprite
	sf::Vector2f m_acceleration; //Holds the abductors current acceleration
	float m_health; //Holds the abductors current health
	bool m_abducting; //Determines whether or not the abductor is currently abducting a target
	float maxSpeed; //Sets the max speed for the abductor
	bool m_flock; //sets whether or not the abductor is currently flocking
	bool m_seek; //Sets whether or not the abductor is seeking
	int index; //Gets the index in a loop for the current abductor
	int neighbourCount; //Keeps track of how many other abductors are nearby
	float m_bulletTimer; //Sets the interval between firing bullets
	sf::Vector2f v; //Computational vector for flocking
	sf::Vector2f pointToFlock; //Position for the flock to move towards
	sf::Vector2f cohesion; //Holds the returned value from the cohesion method
	sf::Vector2f separation; //Holds the returnd value from the separation method
	sf::Vector2f alignment; //Holds the returned value from the alignment method
	bool m_following; //Determines whether or not the abductor is currently already following a target
	int health; //Holds the abductors current health
	sf::Vector2f m_generatedPos; //Holds a position for an individual abductor to wander to 
};