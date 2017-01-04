#pragma once

#include "SFML\Graphics.hpp"

class obstacles
{
   public:

	   obstacles(sf::Vector2f _pos,sf::Texture _tex, sf::Vector2f _vel, float _gameHeight, float _gameWidth);
	   ~obstacles();
	   sf::Sprite getSprite();
	   void update();
  private:
	  float m_gameHeight;
	  float m_gameWidth;
	  sf::Vector2f m_pos;
	  sf::Sprite m_Sprite;
	  sf::Vector2f m_Vel;
	  sf::Texture m_tex;
};