#pragma once

#include "SFML\Graphics.hpp"

class obstacles
{
   public:

	   obstacles(sf::Vector2f _pos,sf::Texture _tex,  float m_leftSpawnBoundary, float m_rightSpawnBoundary, float leftSpawn, float rightSpawn);
	   ~obstacles();
	   sf::Sprite getSprite();
	   void update();
  private:
	  float m_rightSpawnBoundary;
	  float m_leftSpawnBoundary;
	  sf::Vector2f m_pos;
	  sf::Sprite m_Sprite;
	  sf::Vector2f m_Vel;
	  sf::Texture m_tex;
	  float m_leftSpawn,  m_rightSpawn;
};