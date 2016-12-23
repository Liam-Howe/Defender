#ifndef PLAY_HPP
#define PLAY_HPP

#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "Player.h"
#include "Menu.hpp"

class Play : public GameState
{
private:
	
	//Player porperties
	Player * _player;
	sf::Texture _playerTexture;


	//backgorund properties
	sf::Texture _backgorundTexture;
	sf::Sprite _backgroundSprite;

public:

	virtual void draw();
	
	virtual void update();
	virtual void handleInput();

	~Play();

	Play(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */