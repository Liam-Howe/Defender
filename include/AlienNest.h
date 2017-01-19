#pragma once

#include "SFML\Graphics.hpp"
#include "Bullet.h"

class AlienNest
{

public :
	AlienNest(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex);
	~AlienNest();
	
	sf::Sprite getSprite(); //Returns the current sprite
	sf::Vector2f getPosition(); //Returns the current position

	void update(sf::Vector2f playerPos, sf::Texture _alienMissile); //The alien nests update loop

	

	void wander(); //Allows the nest to wander around the game world when no other behaviour is active
	void flee(sf::Vector2f playerPos); //Causes the nest to move away from the passed in position

	sf::Vector2f Normalise(sf::Vector2f velocity); //Normalises the vector passed into it
	sf::RectangleShape getCollisionRect(); //Returns the collision rectangle

	int getAbductorCount(); //Returns the number of abductors spawned from the nest
	void setAbductorCount(int value); //Sets the number of abductors currently spawned

	int getBulletCount();
	void setBulletCount(int value);

	int getAbductorSpawnTimer();
	void setAbductorSpawnTimer(int value);

	int getHealth(); //Returns the nests health
	void takeDamage(int value); //Decrements the nests health
	std::vector<Bullet*>& getBullets(); //Returns the nests bullets
private:

	sf::RectangleShape collisionBox; //Creates a rectangle for the nests collision
	std::vector<Bullet *> _nestBulletVector; //Holds all the nests bullets
	sf::Vector2f generatedPos;//Holds a generated position for the nest to wander to
	float playerDistance; //Holds distance between the player and the nest

	int bulletTimer; //Timer for interval between firing bullets
	bool m_Afleeing; //Determines whether or not the nest is fleeing

	int bulletCount; //Keeps track of the number of bullets fired
	int abductorSpawnTimer; //Timer for the spawn of abductors

	sf::Vector2f m_APos; //Holds the nests current position
	sf::Vector2f m_AVel; //Holds the nests current velocity
	sf::Texture m_ATex; //Holds the nests current texture
	sf::Sprite m_ASprite; //Holds the nests current sprite
	int abductorCount; //Holds the number of abductors spawned

	int health; //Keeps track of the nests health

};
