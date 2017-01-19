#pragma once

#include "SFML\Graphics.hpp"
#include "Bullet.h"

class Mutant 
{

public:
	Mutant(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex);
	~Mutant();
	sf::Vector2f getVelocity();
	void setindex(int value);
	sf::Vector2f computeAlignment(std::vector<Mutant*> agents);
	sf::Vector2f computeCohesion(std::vector<Mutant*> agents);
	sf::Vector2f computeSeparation(std::vector<Mutant*> agents);
	sf::Vector2f getPosition(); //Returns the current position
	void setPosition(sf::Vector2f _tempPos); //Sets the mutants position to a recieved vector
	sf::Sprite getSprite(); //Returns the mutants sprite
	sf::RectangleShape getCollisionRect(); //Returns the mutants collision box
	void update(); //The mutants update loop
	void seek(sf::Vector2f targetPos); //Causes the mutant to move towards the passed in target
	sf::Vector2f Normalise(sf::Vector2f velocity); //Normalises the vector passed into it
	void wander(std::vector<Mutant*> agents);
	void movement(sf::Vector2f targetPos, sf::Texture _playerBullet); //Allows the mutant to move and change behaviour 
	void fire(sf::Vector2f targetPos, sf::Texture _playerBullet); //Creates a new bullet and fires it at the position passed in
	void swarm(); //Causes a group of mutants to swarm 
	int getHealth(); //Returns the current value for mutant health
	void takeDamage(int value); //Decrements the mutants health
	std::vector<Bullet*>& getBullets(); //Returns the current bullets in the mutants bullet vector

private:
	std::vector<Bullet*> _mutantBulletVector; //Holds all the mutants bullets
	sf::RectangleShape collisionBox; //Creates a box around the mutant for collisions
	sf::Vector2f m_pos; //Holds the mutants current position
	sf::Vector2f m_vel; //Holds the mutants current velocity
	sf::Texture m_tex; //Holds the mutants current texture
	sf::Sprite m_sprite; //Holds the mutants current sprite
	float bulletTimer; //Timer for interval between firing bullets
	bool m_seek; //Determines whether or not the mutant is currently seeking towards a target
	int health; //Holds the mutants current health
	float m_neighourCount;
	sf::Vector2f v;
	int m_index;
	sf::Vector2f m_pointToFlock;
	sf::Vector2f m_generatedPos, m_cohesion,m_alignment,m_seperation;
};