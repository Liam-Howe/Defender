
#include "../include/Play.hpp"


Play::Play(Game* game)
{
	this->game = game;
	game->window.setFramerateLimit(60); 
	_playerTexture.loadFromFile("Assets/ship.png");
	_player = new Player(sf::Vector2f(400,300),sf::Vector2f(0,0),_playerTexture);
	_backgorundTexture.loadFromFile("Assets/back.png");
	_backgroundSprite.setTexture(_backgorundTexture);

} 


void Play::draw()
{	
	return;
}


void Play::update()
{
	game->window.clear(sf::Color::Red);
	game->window.draw(_backgroundSprite);
	game->window.draw(_player->getSprite());
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

		if (event.key.code == sf::Keyboard::W)
		{
			_player->move(sf::Vector2f(0, -1));
		}
		 if (event.key.code == sf::Keyboard::D)
		{
			_player->move(sf::Vector2f(1, 0));
		}
		 if (event.key.code == sf::Keyboard::S)
		{
			_player->move(sf::Vector2f(0, 1));
		}
		 if (event.key.code == sf::Keyboard::A)
		{
			_player->move(sf::Vector2f (-1,0));
		}

		return;
	}
}


Play::~Play(
){


}





