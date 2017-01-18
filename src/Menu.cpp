#include "../include/Menu.hpp"
#include "../include/Play.hpp"

Menu::Menu(Game* game)
{
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());

	m_buttonTexture.loadFromFile("Assets/play1.png");
	m_background.loadFromFile("Assets/Menu2.png");
	m_playSprite.setTexture(m_buttonTexture);
	m_backgroundsprite.setTexture(m_background);
	m_playSprite.setOrigin(m_playSprite.getGlobalBounds().width / 2, m_playSprite.getGlobalBounds().height / 2);
	m_playSprite.setPosition(pos.x/2, 500);
}
void Menu::draw()
{
	return;
}

void Menu::update()
{
	
	game->window.draw(m_backgroundsprite);
	game->window.draw(m_playSprite);
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
		game->changeState(new Play(this->game));
	}
	return;	
}

Menu::~Menu()
{

	//while (!this->states.empty()) popState();
}

void Menu::handleInput()
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->game->changeState(new Play(this->game));
	}

	return;
}

bool Menu::checkClicked(sf::Sprite sprite, sf::Vector2i position)
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
