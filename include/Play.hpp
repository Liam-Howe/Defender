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
#include "../Dependencies/Thor/include/Particles.hpp"
#include "../Dependencies/Thor/include/Particles/Affectors.hpp"
#include "../Dependencies/Thor/include/Particles/EmissionInterface.hpp"
#include "../Dependencies/Thor/include/Particles/Emitters.hpp"
#include "../Dependencies/Thor/include/Particles/ParticleSystem.hpp"
#include "../Dependencies/Thor/include/Vectors/VectorAlgebra3D.hpp"
#include "../Dependencies/Thor/include/Particles/ParticleSystem.hpp"
#include "../Dependencies/Thor/include/Math/Distributions.hpp"


class Play : public GameState
{
private:
	
	CollisionManager _collisionManager;
//	thor::ParticleSystem system;
	sf::Clock Particleclock;
//	thor::UniversalEmitter Snowemitter1;
	//thor::UniversalEmitter Snowemitter2;
	//thor::UniversalEmitter Snowemitter3;
	//Player porperties
	Player * _player;
	sf::Texture _playerTexture;
	sf::View _playerView;
	sf::View _radarView;
	std::vector<Bullet *> _playerBulletVector;
	sf::Texture _playerBullet;
	sf::Texture _nestTexture;
	
	int _spawnLeft;
	int _spawnRight;
	int _rightSpawnBoundary;
	int _leftSpawnBoundary;

	std::vector<AlienNest*> m_nests;
	sf::Texture _alienMissile;

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

public:

	virtual void draw();
	void CollisionManager();
	void updateCamera();
	void wrapAround();
	virtual void update();
	virtual void handleInput();
	void updatePlayerBullet();
	void checkHealth();
	~Play();

	Play(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */