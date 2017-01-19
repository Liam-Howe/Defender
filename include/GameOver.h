#pragma once

#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "Menu.hpp"
class GameOver : public GameState
{
private:
	sf::Texture m_buttonTexture;//texture for button on screeen
	sf::Vector2i windowPosition;
	sf::Vector2i m_Mouseposition;//postiion of mouse on screen
	sf::Texture m_background;//background texture
	sf::Sprite m_playSprite, m_backgroundsprite;//game over sprites
	sf::Text m_scoreText;//score text
	sf::Font font;
	int m_score;//players score
public:

	virtual void draw();
	virtual void update();
	virtual void handleInput();
	bool checkClicked(sf::Sprite sprite, sf::Vector2i pos);//checks to see if the menu button has been clicked
	~GameOver();
	GameOver(Game* game,int);
};