#include "../include/GameOver.h"

GameOver::GameOver(Game* game ,int _score ) : m_score(_score)
{
	this->game = game;
	
	if (m_state)
	{
		m_background.loadFromFile("Assets/win.png");
	} 
	else
	{
		m_background.loadFromFile("Assets/lose.png");
	}
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	sf::View _view;
	_view.setSize(1200, 800);
	_view.setCenter(game->window.getSize().x / 2, game->window.getSize().y / 2);
	game->window.setView(_view);
	m_buttonTexture.loadFromFile("Assets/exit2.png");
	
	font.loadFromFile("Assets/arial.ttf");
	m_scoreText = sf::Text(" Your Score  : " + std::to_string(m_score), font);
	m_scoreText.setCharacterSize(30);
	m_scoreText.setStyle(sf::Text::Bold);
	m_scoreText.setPosition(sf::Vector2f(pos.x / 2.5, pos.y / 1.4f));

	m_playSprite.setTexture(m_buttonTexture);
	m_backgroundsprite.setTexture(m_background);
	m_playSprite.setPosition(1500, 500);
	m_playSprite.setOrigin(m_playSprite.getGlobalBounds().width / 2, m_playSprite.getGlobalBounds().height / 2);
	m_playSprite.setPosition(pos.x / 2, pos.y/1.2f);


}
void GameOver::draw()
{
	return;
}

void GameOver::update()
{

	game->window.draw(m_backgroundsprite);
	game->window.draw(m_playSprite);
	game->window.draw(m_scoreText);
	game->window.display();
	m_Mouseposition = sf::Mouse::getPosition(game->window);
	if (checkClicked(m_playSprite, m_Mouseposition) == true && sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
	{
		m_playSprite.setTextureRect(sf::IntRect(0, 0, 0, 0));
	}
	else if (checkClicked(m_playSprite, m_Mouseposition) == false)
	{
		m_playSprite.setTextureRect(sf::IntRect(0, 0, 201, 71));
	}

	if (checkClicked(m_playSprite, m_Mouseposition) == true && sf::Mouse::isButtonPressed(sf::Mouse::Left) == true)
	{
		game->changeState(new Menu(this->game));
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

	/*if (event.key.code == sf::Keyboard::W)
	{
		this->game->changeState(new Menu(this->game));
	}*/

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
