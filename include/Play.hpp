#ifndef PLAY_HPP
#define PLAY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include "game_state.hpp"
#include "Player.h"
#include "Menu.hpp"
#include "obstacles.h"
#include "Mutant.h"
#include "Astronaut.h"
#include "Bullet.h"
#include "AlienNest.h"
#include "Abductor.h"
#include "CollisionManager.h"
#include "PowerUp.h"
#include "PowerUpType.h"

class Play : public GameState
{
private:
	
	CollisionManager _collisionManager;

	float m_powerUptimer;
	//Player porperties
	Player * _player;
	sf::Texture _playerTexture;
	sf::View _playerView;
	sf::View _radarView;

	sf::Texture _playerBullet;
	sf::Texture _nestTexture;
	
	int _spawnLeft;
	int _spawnRight;
	int _rightSpawnBoundary;
	int _leftSpawnBoundary;

	std::vector<AlienNest*> m_nests;
	sf::Texture _alienMissile;
	//int abductorSpawnTimer;

	std::vector<Mutant*> m_mutants;
	sf::Texture _mutantTexture;
	int _mutantCount;

	std::vector<Astronaut*> m_astronauts;
	sf::Texture _astronautTexture;

	sf::Texture _asteroidTexture;
	//backgorund properties
	sf::Texture _backgorundTexture;
	sf::Sprite _backgroundSprite;
	
	//abductores
	sf::Texture _abtuctorTexture;
	std::vector<Abductor*> _abductors;
	int _abductorCount;

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

	sf::Texture m_powerUpTex;
	std::vector<PowerUp*> m_powerUps;

public:
	void updatePowerUps();
	virtual void draw();
	void CollisionManager();
	void updateCamera();
	void wrapAround();
	virtual void update();
	virtual void handleInput();
	//void updatePlayerBullet();
	void checkHealth();
	~Play();

	Play(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */