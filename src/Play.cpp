
#include "../include/Play.hpp"


Play::Play(Game* game)
{
	this->game = game;

	game->window.setFramerateLimit(60); 

	_playerTexture.loadFromFile("Assets/ship.png");
	_backgorundTexture.loadFromFile("Assets/wrapback.png");
	_astronautTexture.loadFromFile("Assets/astronaut.png");
	_nestTexture.loadFromFile("Assets/nest.png");
	_asteroidTexture.loadFromFile("Assets/asteroids.png");
	_playerBullet.loadFromFile("Assets/playerBullet.png");
	_alienMissile.loadFromFile("Assets/alienMissile.png");

	_player = new Player(sf::Vector2f(400, 400), sf::Vector2f(0, 0), _playerTexture);
	_backgroundSprite.setTexture(_backgorundTexture);

	 gameHeight = 1056;
	 gameWidth = 2848;
	 cameraoffset = 200;
	 heightOffset = gameHeight - cameraoffset;
	 WidthOffset = gameWidth - cameraoffset;

	 srand(time(NULL));

	 int _x =0;
	 int _y =0;
	 int _Ax = 0;
	 int _Nx = 0;
	 int _Ny = 0;

	 for (int i = 0; i < 1; i++)
	 {
		 _Ax = rand() % (1900 - 100 + 1) + 100;
		 Astronaut * _temp = new Astronaut(sf::Vector2f(_Ax, 690), sf::Vector2f(0, 0), _astronautTexture);
		 m_astronauts.push_back(_temp);
	 }

	 for (int i = 0; i < 1; i++)
	 {
		 _Nx = rand() % (1900 - 100 + 1) + 100;
		 _Nx = rand() % 700 + 1;
		 AlienNest * _Atemp = new AlienNest(sf::Vector2f(350, 400), sf::Vector2f(0, 0), _nestTexture);
		 m_nests.push_back(_Atemp);
	 }

	 for (int i = 0; i < 2; i++)
	 {
		 _x = rand() % (1900 - 100 + 1) + 100;
		 _y = rand() % (900 - 100 + 1) + 100;
		 obstacles * _temp = new obstacles(sf::Vector2f(_x,_y),_asteroidTexture,sf::Vector2f(0,-1),gameHeight,gameWidth);
		 m_obstacles.push_back(_temp);
	 }
} 


void Play::draw()
{	
	return;
}


void Play::update()
{
	updateCamera();
	wrapAround();
	_player->update();
	

	if (_playerBulletVector.size() != 0)
	{
		updatePlayerBullet();
	}

	for (int i = 0; i < m_obstacles.size(); i++)
	{
		m_obstacles[i]->update();
	}

	for (int i = 0; i < m_astronauts.size(); i++)
	{
		m_astronauts[i]->movement(_player->getPosition());
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
	//	m_nests[i]->update(_player->getPosition(), _alienMissile);
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		if (m_nests[i]->_nestBulletVector.size() > 0)
		{
			for (int k = 0; k < m_nests[i]->_nestBulletVector.size(); k++)
			{
				m_nests[i]->_nestBulletVector[k]->seekerUpdate(_player->getPosition());
			}
		}
	}

	//game->window.clear(sf::Color::Red);
	game->window.draw(_backgroundSprite);
	game->window.draw(_player->getSprite());
	for (int i = 0; i < m_astronauts.size(); i++)
	{
		game->window.draw(m_astronauts[i]->getSprite());
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		game->window.draw(m_nests[i]->getSprite());
	}

	if (_playerBulletVector.size() >0)
	{
		for (int i = 0; i < _playerBulletVector.size(); i++)
		{
			game->window.draw(_playerBulletVector[i]->getSprite());
		}
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		if (m_nests[i]->_nestBulletVector.size() > 0)
		{
			for (int k = 0; k < m_nests[i]->_nestBulletVector.size(); k++)
			{
				m_nests[i]->_nestBulletVector[k]->getSprite();
			}
		}
	}
	
	for (int i = 0; i < m_obstacles.size(); i++)
	{
		game->window.draw(m_obstacles[i]->getSprite());
	}
	game->window.display();
	return;
}

void Play::updatePlayerBullet()
{
		for (int i = 0; i < _playerBulletVector.size(); i++)
		{
			_playerBulletVector[i]->update();
		}
}

void Play::updateCamera()
{
	sf::View _playerView(sf::Vector2f(_player->getSprite().getPosition().x, _player->getSprite().getPosition().y), sf::Vector2f(400, 400));


	// y checks 
	if (_player->getPosition().y >  heightOffset)
	{
		_playerView.setCenter(sf::Vector2f(_player->getPosition().x, heightOffset));
	}
	else if (_player->getPosition().y < 0 + cameraoffset)
	{
		_playerView.setCenter(sf::Vector2f(_player->getPosition().x, cameraoffset));
	}


	//x checks
	if (_player->getPosition().x < 0 + cameraoffset)
	{
		_playerView.setCenter(sf::Vector2f(cameraoffset, _player->getPosition().y));
	}
	if (_player->getPosition().x < 0 + cameraoffset && _player->getPosition().y > heightOffset)
	{
		_playerView.setCenter(sf::Vector2f(cameraoffset, heightOffset));
	}

	if (_player->getPosition().x > WidthOffset)
	{
		_playerView.setCenter(sf::Vector2f(WidthOffset, _player->getPosition().y));
	}

	//left and lower check
	if (_player->getPosition().x < 0 + cameraoffset && _player->getPosition().y > heightOffset)
	{
		_playerView.setCenter(sf::Vector2f(cameraoffset, heightOffset));
	}
	//right and lower checks
	if (_player->getPosition().x > WidthOffset && _player->getPosition().y > heightOffset)
	{
		_playerView.setCenter(sf::Vector2f(WidthOffset, heightOffset));
	}
	//left and upper check
	if (_player->getPosition().x < 0 + cameraoffset && _player->getPosition().y <  0 + cameraoffset)
	{
		_playerView.setCenter(sf::Vector2f(cameraoffset, cameraoffset));
	}

	//right and upper check
	if (_player->getPosition().x > WidthOffset && _player->getPosition().y <  0 + cameraoffset)
	{
		_playerView.setCenter(sf::Vector2f(WidthOffset, cameraoffset));
	}
	
	game->window.setView(_playerView);
}
void Play::wrapAround()
{
	if (_player->getPosition().x > 2648)
	{
		float tempY = _player->getPosition().y;
		_player->setPosition(sf::Vector2f(600, tempY));
		//_playerView.setCenter(sf::Vector2f(_player->getPosition()));
	}
	if (_player->getPosition().x <= 200)
	{
		float tempY = _player->getPosition().y;
		_player->setPosition(sf::Vector2f(2248, tempY));
		//_playerView.setCenter(sf::Vector2f(_player->getPosition().x, tempY));
	}
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

		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::D)
			{
				_player->setdecelerating(true);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				_player->setdecelerating(true);	
			}
			break;

		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::D)
			{
				_player->setdecelerating(false);
				_player->setdirection(false);
			}
			if (event.key.code == sf::Keyboard::A)
			{
				_player->setdecelerating(false);
				_player->setdirection(true);
			}
			if (event.key.code == sf::Keyboard::Space)
			{
				if (_player->getDirection() == false)
				{
					Bullet * _temp = new Bullet(sf::Vector2f(_player->getPosition().x, _player->getPosition().y), sf::Vector2f(0, 1), _playerBullet, 10);
					_playerBulletVector.push_back(_temp);
				}
				else
				{
					Bullet * _temp = new Bullet(sf::Vector2f(_player->getPosition().x, _player->getPosition().y), sf::Vector2f(0, 1), _playerBullet, -10);
					_playerBulletVector.push_back(_temp);
				}	
			}
			break;
		}

		if (_player->getSprite().getPosition().y - _player->getSprite().getGlobalBounds().height/2 > 0)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				_player->move(sf::Vector2f(0, -10));
			}
		}

		if (_player->getSprite().getPosition().y + _player->getSprite().getGlobalBounds().height / 2 < gameHeight)
		{
			if (event.key.code == sf::Keyboard::S)
			{
				_player->move(sf::Vector2f(0, 10));
			}
		}

		if (event.key.code == sf::Keyboard::D)
		{
			_player->move(sf::Vector2f(10, 0));
		}
		
		if (event.key.code == sf::Keyboard::A)
		{
			_player->move(sf::Vector2f (-10,0));
		}

		return;
	}
}


Play::~Play(
){


}





