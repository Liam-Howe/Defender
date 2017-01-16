#pragma once
#include "SFML\Graphics.hpp"

class Astronaut
{

public:

	Astronaut(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex);
	~Astronaut();

	void movement(sf::Vector2f abductorPos);
	void wander();
	void flee(sf::Vector2f abductorPos);

	sf::Sprite getSprite();
	sf::Vector2f getPosition();

	sf::Vector2f Normalise(sf::Vector2f velocity);
	void update();
	sf::RectangleShape getCollisionRect();
	void setAbducted(bool);
	bool getFollowed();
	bool getAbducted();
	void setFollowed(bool);
	void abducted(sf::Vector2f abductorPos);
private:
	sf::RectangleShape collisionBox;
	sf::Vector2f m_Pos;
	bool m_abducted;
	sf::Vector2f m_Vel;
	sf::Texture m_Tex;
	sf::Sprite m_Sprite;
	float abductorDist;
	float generatedPos;
	bool m_fleeing;
	bool m_followed;
	float m_groundHeight;
};