#include "../include/GameOver.h"

GameOver::GameOver(Game* game)
{
	this->game = game;
	
	/*if (m_play.getWin())
	{
		m_background.loadFromFile("Assets/win.png");
	} 
	else
	{
		m_background.loadFromFile("Assets/lose.png");
	}*/
	//states = game->states;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	sf::View DefaultView;
	DefaultView.setCenter(400, 300);
	DefaultView.setSize(800, 600);
	game->window.setView(DefaultView);
	m_buttonTexture.loadFromFile("Assets/play1.png");
	
	m_playSprite.setTexture(m_background);
	m_backgroundsprite.setTexture(m_background);
	m_playSprite.setPosition(1500, 500);
}
void GameOver::draw()
{
	return;
}

void GameOver::update()
{

	game->window.draw(m_backgroundsprite);
	game->window.draw(m_playSprite);
	game->window.display();
	if (checkClicked(m_playSprite, m_Mouseposition) == true && sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
	{
		m_playSprite.setTextureRect(sf::IntRect(0, 72, 201, 71));
	}



	return;

}

GameOver::~GameOver()
{

	//while (!this->states.empty()) popState();
}

void GameOver::handleInput()
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

		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape) this->game->window.close();
			{

			}
			break;
		}
		default: break;
		}
	}

	if (event.key.code == sf::Keyboard::W)
	{
		this->game->changeState(new Menu(this->game));
	}

	return;
}

bool GameOver::checkClicked(sf::Sprite sprite, sf::Vector2i position)
{
	if (position.x > sprite.getGlobalBounds().left
		&& position.x < (sprite.getGlobalBounds().left + sprite.getGlobalBounds().width)
		&& position.y > sprite.getGlobalBounds().top
		&& position.y < (sprite.getGlobalBounds().top + sprite.getGlobalBounds().height))
	{
		return true;
	}
	else
	{
		return false;
	}
}
