#ifndef PLAY_HPP
#define PLAY_HPP

#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "Player.h"
#include "Menu.hpp"
#include "obstacles.h"
#include "Astronaut.h"
#include "AlienNest.h"
#include "Bullet.h"
class Play : public GameState
{
private:
	
	//Player properties
	Player * _player;
	sf::Texture _playerTexture;
	sf::View _playerView;

	//Bullet properties
	std::vector<Bullet *> _playerBulletVector;
	sf::Texture _playerBullet;
	sf::Texture _alienMissile;

	//Nest properties
	std::vector<AlienNest*> m_nests;
	sf::Texture _nestTexture;

	//Astronaut properties
	std::vector<Astronaut*> m_astronauts;
	sf::Texture _astronautTexture;

	//Obstacle properties
	sf::Texture _asteroidTexture;
	std::vector<obstacles*> m_obstacles;

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
	void updatePlayerBullet();
	~Play();

	Play(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */