#pragma once
#include "SFML\Graphics.hpp"

class Astronaut
{

public:

	Astronaut(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex);
	~Astronaut();

	void movement(sf::Vector2f abductorPos); //Allows the asrtronaut to move and determines behaviour
	void wander(); //Allows the astronaut to wander from point to point
	void flee(sf::Vector2f abductorPos); //Tells the astronaut to flee away from a passed in position

	sf::Sprite getSprite(); //Returns the astronauts position
	sf::Vector2f getPosition(); //Gets the astronauts position

	sf::Vector2f Normalise(sf::Vector2f velocity); //Normalises vectors passed into method
	void update(); //the astronauts update loop
	sf::RectangleShape getCollisionRect(); //Returns the astronauts collision box
	sf::RectangleShape getSeekRect(); //Returns the seeking collision box for the astronaut
	void abducted(sf::Vector2f _abductorPos); //Tells the astronaut what to do when the have been abducted
	void setAbducted(bool); //Sets whether or not the astronaut is being abducted
	bool getAbducted(); //Checks whether or not the astronaut is being abducted
	void setPosition(sf::Vector2f); //Sets the current position to a passed in vector
private:
	bool m_abducted; //Determines if the astronaut is being abducted
	sf::RectangleShape collisionBox; //Creates a box aaround the astronaut for collisions
	sf::RectangleShape seekBox; //Creates a large box around the astronaut to trigger astronauts seeking
	sf::Vector2f m_Pos; //Holds the astronauts current position
	sf::Vector2f m_Vel; //Holds the astronauts current velocity
	sf::Texture m_Tex; //Holds the astronauts current texture
	sf::Sprite m_Sprite; //Holds the astronauts current sprite
	float abductorDist; //Holds distance between the astronaut and abductors
	float generatedPos; //Holds a position for the astronaut to wander to
	bool m_fleeing; //Determines if the astronaut is fleeing
};