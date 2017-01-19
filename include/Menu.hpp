#ifndef MENU_HPP
#define MENU_HPP


#include <SFML/Graphics.hpp>
#include "game_state.hpp"

class Menu : public GameState
{
private:
	sf::Texture m_buttonTexture;//button texture
	sf::Vector2i windowPosition;
	sf::Vector2i m_Mouseposition;//postion of mouse on screen
	sf::Texture m_background;//background texture
	sf::Sprite m_playSprite, m_backgroundsprite;//background and button sprite
public:

	virtual void draw();
	virtual void update();
	virtual void handleInput();
	bool checkClicked(sf::Sprite sprite, sf::Vector2i pos);//checks to see fi the button has been clicked
	~Menu();
	Menu(Game* game);
};

#endif /* GAME_STATE_START_HPP */