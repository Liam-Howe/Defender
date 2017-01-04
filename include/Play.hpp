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
	sf::View _playerView;

	//backgorund properties
	sf::Texture _backgorundTexture;
	sf::Sprite _backgroundSprite;
	float gameHeight;
	float gameWidth;
	float cameraoffset;
	float WidthOffset;
	float heightOffset;
public:

	virtual void draw();
	void updateCamera();
	void wrapAround();
	virtual void update();
	virtual void handleInput();

	~Play();

	Play(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */