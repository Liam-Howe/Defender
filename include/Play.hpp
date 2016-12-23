#ifndef PLAY_HPP
#define PLAY_HPP

#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "SFML\OpenGL.hpp"

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
#include <time.h> 
#include "SFML/OpenGL.hpp" 


#include <iostream> 
#include <array>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include <vector>
#include "Player.h"
#include <math.h>
#include "Menu.hpp"
#include <list>

using namespace std;


class Play : public GameState
{
private:
	

	


public:

	virtual void draw();
	
	virtual void update();
	virtual void handleInput();

	~Play();

	Play(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */