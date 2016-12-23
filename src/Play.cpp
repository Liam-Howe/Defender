#include "../include/stdafx.h"
#include "../include/game_state.hpp"
#include "../include/Play.hpp"





Play::Play(Game* game)
{
	this->game = game;
	game->window.setFramerateLimit(60);    
} 


void Play::draw()
{	
	return;
}


void Play::update()
{
	game->window.clear(sf::Color::Red);

	game->window.display();
	return;
}



void Play::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
			/* Close the window */
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}
		/* Resize the window */
		}

		return;
	}
}


Play::~Play(
){


}





