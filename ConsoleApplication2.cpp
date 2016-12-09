//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
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
#include "Player.h"



////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	// Create the main window 
	sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "SFML First Program");

	//load a font
	//sf::Font font;
	//font.loadFromFile("C:\\Windows\\Fonts\\GARA.TTF");

	////create a formatted text string
	//sf::Text text;
	//text.setFont(font);
	//text.setString("Hello World");
	//text.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	//text.setPosition(20, 40);
	//text.setCharacterSize(40);

	////create a circle
	//sf::CircleShape circle(50);
	//circle.setPosition(300, 200);
	sf::Texture playerTex;
	sf::Texture background2;
	background2.loadFromFile("back.png");
	sf::Sprite backgorund;
	backgorund.setTexture(background2);
	backgorund.setPosition(0, 0);
	playerTex.loadFromFile("ship.png");
	Player *_player = new Player(sf::Vector2f(200, 200),sf::Vector2f(1,1),playerTex);
	sf::View view1(sf::Vector2f(_player->getSprite().getPosition().x,_player->getSprite().getPosition().y),sf::Vector2f(300, 463));

	// Start game loop 
	while (window.isOpen())
	{
		// Process events 
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			// Close window : exit 
			if (Event.type == sf::Event::Closed)
				window.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
				window.close();

			// Escape key : exit 
			if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::W))
			{
				_player->move(sf::Vector2f(0,-0.001));
				sf::View view1(sf::Vector2f(_player->getSprite().getPosition().x, _player->getSprite().getPosition().y), sf::Vector2f(300, 463));
			}
			// Escape key : exit 
			else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::S))
			{
				_player->move(sf::Vector2f(0,0.001));
			  
			}
			else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::D))
			{
				_player->move(sf::Vector2f(0.001, 0));

			}
			else if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::A))
			{
				_player->move(sf::Vector2f(-0.001, 0));
			}
		}
		view1 = sf::View(sf::Vector2f(_player->getSprite().getPosition().x, _player->getSprite().getPosition().y), sf::Vector2f(300, 463));
		//prepare frame
		window.clear();
		window.setView(view1);
		window.draw(backgorund);
		window.draw(_player->getSprite());
		//draw frame items
		/*window.draw(text);

		window.draw(circle);*/


		// Finally, display rendered frame on screen 
		window.display();
	} //loop back for next frame

	return EXIT_SUCCESS;
}