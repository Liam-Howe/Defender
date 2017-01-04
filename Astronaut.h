#pragma once

class Astronaut :: public AI
{

public:

	Astronaut()
	~Astronaut();

	sf::Sprite getSprite();
	void movement();
private:

	sf::Vector2f m_AstroPos;
	sf::Vector2f m_AstroVel;
	sf::Vector2f m_AstroAccel;
	sf::Texture m_AstroTex;
	sf::Sprite m_AstroSprite;

};