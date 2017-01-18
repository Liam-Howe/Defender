#pragma once

#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "Play.hpp"
class GameOver : public GameState
{
private:
	sf::Texture m_buttonTexture;
	sf::Texture m_selectTexture;
	sf::Vector2i windowPosition;
	sf::Vector2i m_Mouseposition;
	sf::Texture m_background;
	sf::Sprite m_playSprite, m_backgroundsprite;
	
public:

	virtual void draw();
	virtual void update();
	virtual void handleInput();
	bool m_winState;
	bool checkClicked(sf::Sprite sprite, sf::Vector2i pos);
	~GameOver();
	GameOver(Game* game);
};