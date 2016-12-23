//#include "../stdafx.h"
#include <stack>
//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "../include/game.hpp"
#include "../include/game_state.hpp"
#include "../include/Play.hpp"
//#include "Menu.hpp"

void Game::pushState(GameState* state)
{
	this->states.push(state);
	return;
}


void Game::popState()
{
	delete this->states.top();
	this->states.pop();

	return;
}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
		popState();
	pushState(state);

	return;
}

GameState* Game::peekState()
{
	if (this->states.empty()) return nullptr;
	return this->states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;
//	Player *_player = new Player(sf::Vector2f(200, 200), sf::Vector2f(1, 1), playerTex);
	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
	//	float dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update();
	//	this->window.clear(sf::Color::Black);
		peekState()->draw();
	//	this->window.display();
		sf::Event Event;
		//while (window.pollEvent(Event))
		//{
		//	// Close window : exit 
		//	if (Event.type == sf::Event::Closed)
		//		window.close();

		//	// Escape key : exit 
		//	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
		//		window.close();

		//	// Escape key : exit 
		//	if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::W))
		//	{
		//		_player->move(sf::Vector2f(0, -0.001));
		//		sf::View view1(sf::Vector2f(_player->getSprite().getPosition().x, _player->getSprite().getPosition().y), sf::Vector2f(300, 463));
		//	}
		//	// Escape key : exit 
		//	else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::S))
		//	{
		//		_player->move(sf::Vector2f(0, 0.001));

		//	}
		//	else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::D))
		//	{
		//		_player->move(sf::Vector2f(0.001, 0));

		//	}
		//	else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::A))
		//	{
		//		_player->move(sf::Vector2f(-0.001, 0));
		//	}
		//}
	
	}
}

Game::Game()
{
	this->window.create(sf::VideoMode(800, 600), "ET WARS");//,sf::Style::Fullscreen);
	this->window.setFramerateLimit(60);
	this->window.setVerticalSyncEnabled(true);
}

Game::~Game()
{
	
	while (!this->states.empty()) popState();
}