#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>

class GameState;

class Game
{
public:
	//vector of states
	std::stack<GameState*> states;

	sf::RenderWindow window;

	void pushState(GameState* state);//ads a new state tot this vector
	void popState();//deletes a state from the vector
	void changeState(GameState* state);//avility to change states
	GameState* peekState();

	void gameLoop();

	Game();
	~Game();
};

#endif /* GAME_HPP */