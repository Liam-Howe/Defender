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
#define _USE_MATH_DEFINES
#include "./include/Menu.hpp"


////////////////////////////////////////////////////////////
///Entrypoint of application 
//////////////////////////////////////////////////////////// 

int main()
{
	Game * game = new Game();
	game->changeState(new Menu(game));
	//return 0;
	sf::Clock clock;

	while (game->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		//	float dt = elapsed.asSeconds();

		if (game->peekState() == nullptr) continue;
		game->peekState()->handleInput();
		game->peekState()->update();
		//	this->window.clear(sf::Color::Black);
		game->peekState()->draw();
		//	this->window.display();

	}
	//return EXIT_SUCCESS;
}