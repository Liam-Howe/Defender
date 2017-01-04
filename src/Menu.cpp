#include "../include/Menu.hpp"
#include "../include/Play.hpp"

Menu::Menu(Game* game)
{
	this->game = game;
	//states = game->states;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	sf::View DefaultView;
	DefaultView.setCenter(400, 300);
	DefaultView.setSize(800, 600);
	game->window.setView(DefaultView);

}
void Menu::draw()
{
	return;
}

void Menu::update()
{
	game->window.clear(sf::Color::Cyan);

	game->window.display();

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

	if (event.key.code == sf::Keyboard::W)
	{
		this->game->changeState(new Play(this->game));
	}

	return;
}