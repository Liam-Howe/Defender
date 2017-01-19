#pragma once

#include "SFML\Graphics.hpp"

class obstacles
{
   public:

	   obstacles(sf::Vector2f _pos,sf::Texture _tex,  float m_leftSpawnBoundary, float m_rightSpawnBoundary, float leftSpawn, float rightSpawn);//constructs
	   ~obstacles();
	   sf::Sprite getSprite();//returns asteroid sprite
	   void update();
	   sf::RectangleShape getCollisionRect();
  private:
	  float m_rightSpawnBoundary;//position on the right of the screen at which the asteroid will wrap around
	  float m_leftSpawnBoundary;//position on the left of the screen at which the asteroid will wrap around
	  sf::Vector2f m_pos;//position of the asteroid
	  sf::Sprite m_Sprite;//sprite for the asteroid
	  sf::Vector2f m_Vel;//velocity of the asteroid
	  sf::Texture m_tex;//texture of the asteroid
	  float m_leftSpawn,  m_rightSpawn;//positions at which the asteroid 
	  sf::RectangleShape m_rectangle;
};