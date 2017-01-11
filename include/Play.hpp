#ifndef PLAY_HPP
#define PLAY_HPP

#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "Player.h"
#include "Menu.hpp"
#include "obstacles.h"
#include "Astronaut.h"
#include "Bullet.h"
#include "AlienNest.h"
class Play : public GameState
{
private:
	
	//Player porperties
	Player * _player;
	sf::Texture _playerTexture;
	sf::View _playerView;
	std::vector<Bullet *> _playerBulletVector;
	sf::Texture _playerBullet;
	sf::Texture _nestTexture;
	
	int _spawnLeft;
	int _spawnRight;
	int _rightSpawnBoundary;
	int _leftSpawnBoundary;

	std::vector<AlienNest*> m_nests;
	sf::Texture _alienMissile;

	std::vector<Astronaut*> m_astronauts;
	sf::Texture _astronautTexture;

	sf::Texture _asteroidTexture;
	//backgorund properties
	sf::Texture _backgorundTexture;
	sf::Sprite _backgroundSprite;
	

	float gameHeight;
	float gameWidth;
	float cameraoffset;
	float WidthOffset;
	//float heightOffset;
	std::vector<obstacles*> m_obstacles;
	//Astronaut
	Astronaut * _astro;
	sf::Texture _astroTexture;
	float  _dt;
	sf::Clock _clock;

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