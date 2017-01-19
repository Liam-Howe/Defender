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
#include "SFML\Audio\Sound.hpp"
#include "SFML\Audio\SoundBuffer.hpp"
#include "SFML\Audio\Music.hpp"
#include "GameOver.h"

class Play : public GameState
{
private:
	
	CollisionManager _collisionManager;//instance of collision manager

	float m_powerUptimer;//time for the pwoer ups to live
	//Player porperties
	Player * _player;//instnace of player
	sf::Texture _playerTexture;//texture for player
	
	//views
	sf::View _playerView;//camera that follows the player
	sf::View _radarView;//radar camera

	sf::Texture _playerBullet;
	sf::Texture _nestTexture;
	
	//wrap around variables
	int _spawnLeft;//position in which the object spawns at on the left if wrapped around
	int _spawnRight;//position in which the object spawns at on the right if wrapped around
	int _rightSpawnBoundary;//poisition to the right of the screen at which the player will wrap to the other side
	int _leftSpawnBoundary;//poisition to the left of the screen at which the player will wrap to the other side
	

	//nest variables
	std::vector<AlienNest*> m_nests;//vector fo alien nests
	sf::Texture _alienMissile;//alien bullet texture
	int m_nestCount;//number of nests

	//mutant properties
	std::vector<Mutant*> m_mutants;//vector fo alien mutants
	sf::Texture _mutantTexture;//mutant bullet texture
	int _mutantCount;//mutant count


	//astronaut properties
	std::vector<Astronaut*> m_astronauts;//vector of astronauts
	sf::Texture _astronautTexture;//astronauts  texture

	 //asteroid properties
	std::vector<obstacles*> m_obstacles;//vector of asteroids
	sf::Texture _asteroidTexture;//asteroids texture
	int m_astronautCount;//astronaut count
								 
								 //backgorund properties
	sf::Texture _backgorundTexture;
	sf::Sprite _backgroundSprite;
	
	//abductores
	sf::Texture _abtuctorTexture;
	std::vector<Abductor*> _abductors;
	int _abductorCount;

	float gameHeight;//height of game world
	float gameWidth;//width of game world
	
	float cameraoffset;//offset properties for camera
	float WidthOffset;
	
	
	
	
	float  _dt;//deltatime
	sf::Clock _clock;

	//power up proeperties
	sf::Texture m_powerUpTex;//power up texture
	std::vector<PowerUp*> m_powerUps;//vector of power ups

	

	//sounds
	sf::SoundBuffer m_buffer, m_explosionbuffer, m_powerUpBuffer;//sound buffers
	sf::Sound m_playerFire;//sound for when the player fires
	sf::Sound m_powerUpSound;//sound for when the player gets a pwoer up
	sf::Sound m_nestBullet;//sound for when the nest fires a bullet 
	sf::Sound m_seekerBullet;//sound for seeker bullets
	sf::Sound m_explosion;//sound for when entities are destroyed
	sf::Music m_music;//background music

	//round text
	sf::Text m_roundText;
	sf::Text m_hyperJumpText;//text displays status of hyperjump ability
	sf::Text m_scoreText;//text displays the users current score
	sf::Text m_health;//text displays the users current health 
	
	int m_round;//tracks current round
	int m_score;//tracks current score
	
	sf::Font font;

public:
	//updates power up properties
	void updatePowerUps();
	//inherited draw fucntion
	virtual void draw();
	//handles collisions between entitites
	void CollisionManager();
	//updartes camera views
	void updateCamera();
	//increases round 
	void increaseRound();
	//increases score
	void increaseScore();
	//detecsts if the player should wrap around
	void wrapAround();
	//updates the game loop
	virtual void update();
	//checks if the scen state should be set to game over
	void activateGameOverState();
	//checks for user input
	virtual void handleInput();
	//void updatePlayerBullet();
	void checkHealth();
	~Play();
	//checjs the status fo the rounds
	void updateRounds();
	Play(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */