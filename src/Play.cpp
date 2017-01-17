
#include "../include/Play.hpp"


Play::Play(Game* game)
{
	this->game = game;

	game->window.setFramerateLimit(60); 
	
	
	_playerTexture.loadFromFile("Assets/ship.png");
	_player = new Player(sf::Vector2f(1424,400),sf::Vector2f(0,0),_playerTexture);
	_nestTexture.loadFromFile("Assets/nest.png");
	_backgorundTexture.loadFromFile("Assets/back2.png");
	_astronautTexture.loadFromFile("Assets/astronaut.png");
	//_astro = new Astronaut(sf::Vector2f(100, 100), sf::Vector2f(0, 0), _astronautTexture);
	_backgroundSprite.setTexture(_backgorundTexture);
	_asteroidTexture.loadFromFile("Assets/asteroids.png");
	_playerBullet.loadFromFile("Assets/playerBullet.png");
	_alienMissile.loadFromFile("Assets/alienMissile.png");
	_abtuctorTexture.loadFromFile("Assets/abductor.png");
	_mutantTexture.loadFromFile("Assets/mutant.png");
	 gameHeight = 1056;
	 gameWidth = 6600;
	 cameraoffset = 300;
	
	 WidthOffset = gameWidth - cameraoffset;

	 _spawnLeft = 900;
	 _spawnRight = 5700;
	 _rightSpawnBoundary = 6300;
	 _leftSpawnBoundary = 300;
	 _radarView.setCenter(sf::Vector2f(gameWidth/2, gameHeight / 2));
	 _radarView.setSize(sf::Vector2f(6600, 1056));
	 _radarView.setViewport(sf::FloatRect(0.2, 0.83, 0.6, 0.25));
	 
	 
	 srand(time(NULL));

	 int _x =0;
	 int _y =0;
	 int _Ax = 0;
	 int _Nx = 0;
	 int _Ny = 0;


	 for (int i = 0; i < 2; i++)
	 {
		 _Ax = rand() % (1900 - 100 + 1) + 100;
		 Astronaut * _temp = new Astronaut(sf::Vector2f(_Ax, 690), sf::Vector2f(0, 0), _astronautTexture);
		 m_astronauts.push_back(_temp);
	 }

	 for (int i = 0; i < 1; i++)
	 {
		 _Nx = rand() % (1900 - 100 + 1) + 100;
		 _Nx = rand() % 700 + 1;
		 AlienNest * _Atemp = new AlienNest(sf::Vector2f(1200, 400), sf::Vector2f(0, 0), _nestTexture);
		 m_nests.push_back(_Atemp);
	 }

	 for (int i = 0; i < 2; i++)
	 {
		 _x = rand() % (2200 - 600 + 1) + 100;
		 _y = rand() % (600 - 100 + 1) + 100;
		 obstacles * _temp = new obstacles(sf::Vector2f(_x,_y),_asteroidTexture,sf::Vector2f(0,-1),gameHeight,gameWidth);
		 m_obstacles.push_back(_temp);
	 }

	 _abductorCount = 1;
	 float _tx = 0;

	 for (int i = 0; i < _abductorCount; i++)
	 {
		 float _x = rand() % (2200 - 600 + 1) + 100;
		 Abductor* _temp = new Abductor(sf::Vector2f(1424, 100), sf::Vector2f(0, 0), _abtuctorTexture);
		 _abductors.push_back(_temp);
	}

	//_mutantCount = 1;

	//for (int i = 0; i < _mutantCount; i++)
	//{
	//	float _x = rand() % (2200 - 600 + 1) + 100;
	//	Mutant* _temp = new Mutant(sf::Vector2f(1600, 100), sf::Vector2f(0, 0), _mutantTexture);
	//	m_mutants.push_back(_temp);
	//}
} 


void Play::draw()
{	
	game->window.draw(_backgroundSprite);
	game->window.draw(_player->getSprite());

	for (int i = 0; i < m_astronauts.size(); i++)
	{
		game->window.draw(m_astronauts[i]->getSprite());
	}

	if (_playerBulletVector.size() >0)
	{
		for (int i = 0; i < _playerBulletVector.size(); i++)
		{
			game->window.draw(_playerBulletVector[i]->getSprite());
		}
	}

	if(m_mutants.size() > 0)
	{
		for (int i = 0; i < m_mutants.size(); i++)
		{
			game->window.draw(m_mutants[i]->getSprite());
		}
	}

	for (int i = 0; i < m_mutants.size(); i++)
	{
		if (m_mutants[i]->_mutantBulletVector.size() > 0)
		{
			for (int k = 0; k < m_mutants[i]->_mutantBulletVector.size(); k++)
			{
				game->window.draw(m_mutants[i]->_mutantBulletVector[k]->getSprite());
			}
		}
	}

	if (_abductors.size() >0)
	{
		for (int i = 0; i < _abductorCount; i++)
		{
			game->window.draw(_abductors[i]->getSprite());
		}
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		game->window.draw(m_nests[i]->getSprite());
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		if (m_nests[i]->_nestBulletVector.size() > 0)
		{
			for (int k = 0; k < m_nests[i]->_nestBulletVector.size(); k++)
			{
				game->window.draw(m_nests[i]->_nestBulletVector[k]->getSprite());
			}
		}
	}

	for (int i = 0; i < m_obstacles.size(); i++)
	{
		game->window.draw(m_obstacles[i]->getSprite());
	}
	
	return;
}

void Play::CollisionManager()
{
	for (int i = 0; i < _abductors.size(); i++)
	{
		for (int k = 0; k < m_astronauts.size(); k++)
		{
			if (_collisionManager.collision(_abductors[i]->getCollisionRect(),m_astronauts[0]->getCollisionRect()))
			{
				_abductors[i]->m_abducting = true;
				m_astronauts[0]->m_abducted = true;
			}
			else
			{
				_abductors[i]->m_abducting = false;
				m_astronauts[0]->m_abducted = false;
			}

			/*if (_collisionManager.collision(_abductors[i]->getCollisionRect(), m_astronauts[k]->getCollisionRect()) == false)
			{
				m_astronauts[k]->m_abducted = false;
			}*/
		}
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		for (int k = 0; k < m_nests[i]->_nestBulletVector.size(); k++)
		{
			if (_collisionManager.collision(m_nests[i]->_nestBulletVector[k]->getCollisionRect(),_player->getCollisionRect()))
			{
				m_nests[i]->_nestBulletVector.erase(m_nests[i]->_nestBulletVector.begin() + i);
				m_nests[i]->bulletCount--;
		
				if (_player->getHealth() > 0)
				{
					_player->takeDamage(1);
				}
			}
		}
	}

	for (int i = 0; i < m_mutants.size(); i++)
	{
		for (int k = 0; k < m_mutants[i]->_mutantBulletVector.size(); k++)
		{
			if (_collisionManager.collision(m_mutants[i]->_mutantBulletVector[k]->getCollisionRect(), _player->getCollisionRect()))
			{
				m_mutants[i]->_mutantBulletVector.erase(m_mutants[i]->_mutantBulletVector.begin() + i);
				//m_mutant[i]->bulletCount--;

				if (_player->getHealth() > 0)
				{
					_player->takeDamage(1);
				}
			}
		}
	}

	for (int i = 0; i < _playerBulletVector.size(); i++)
	{
		for (int k = 0; k < m_mutants.size(); k++)
		{
			if (_collisionManager.collision(_playerBulletVector[i]->getCollisionRect(), m_mutants[k]->getCollisionRect()))
			{
				_playerBulletVector.erase(_playerBulletVector.begin() + i);

				if (m_mutants[k]->getHealth() > 0)
				{
					m_mutants[k]->takeDamage(1);
				}
			}
		}
	}

	for (int i = 0; i < _playerBulletVector.size(); i++)
	{
		for (int k = 0; k < m_nests.size(); k++)
		{
			if (_collisionManager.collision(_playerBulletVector[i]->getCollisionRect(), m_nests[k]->getCollisionRect()))
			{
				_playerBulletVector.erase(_playerBulletVector.begin() + i);

				if (m_nests[k]->getHealth() > 0)
				{
					m_nests[k]->takeDamage(1);
				}
			}
		}
	}

	for (int i = 0; i < _playerBulletVector.size(); i++)
	{
		for (int k = 0; k < _abductors.size(); k++)
		{
			if (_collisionManager.collision(_playerBulletVector[i]->getCollisionRect(), _abductors[k]->getCollisionRect()))
			{
				_playerBulletVector.erase(_playerBulletVector.begin() + i);

				if (_abductors[k]->getHealth() > 0)
				{
					_abductors[k]->m_abducting = false;
					//_abductors[k]->setPosition(sf::Vector2f(_abductors[k]->getPosition().x, 2000));
					_abductors[k]->takeDamage(1);
				}
			}
		}
	}

	for (int i = 0; i < _playerBulletVector.size(); i++)
	{
		for (int k = 0; k < m_astronauts.size(); k++)
		{
			if (_collisionManager.collision(_playerBulletVector[i]->getCollisionRect(), m_astronauts[k]->getCollisionRect()))
			{
				//_playerBulletVector.erase(_playerBulletVector.begin() + i);

				m_astronauts[k]->m_abducted = false;
			}
		}
	}
}

void Play::update()
{
	_dt = _clock.restart().asSeconds();

	updateCamera();
	wrapAround();
	_player->update(_dt);

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
		for (int j = 0; j < _abductors.size(); j++)
		{
			m_astronauts[i]->movement(_abductors[j]->getPosition());
		}
	}

	for (int i = 0; i < m_mutants.size(); i++)
	{
		m_mutants[i]->movement(_player->getPosition(), _alienMissile);
	}

	for (int i = 0; i < _abductors.size(); i++)
	{
		if (_abductors[i]->getPosition().y < 0)
		{
			_abductors.erase(_abductors.begin() + i);
		}
	}

	for (int i = 0; i < m_mutants.size(); i++)
	{
		if (m_mutants[i]->_mutantBulletVector.size() > 0)
		{
			for (int k = 0; k < m_mutants[i]->_mutantBulletVector.size(); k++)
			{
				m_mutants[i]->_mutantBulletVector[k]->mutantUpdate(_player->getPosition());
			}
		}
	}

	for (int i = 0; i < m_astronauts.size(); i++)
	{
		if (m_astronauts[i]->getPosition().y < 10)
		{
			Mutant* _temp = new Mutant(sf::Vector2f(m_astronauts[i]->getPosition().x, m_astronauts[i]->getPosition().y), sf::Vector2f(0, 0), _mutantTexture);
			m_mutants.push_back(_temp);
			m_astronauts.erase(m_astronauts.begin() + i);
		}
	}
	
	for (int i = 0; i < m_nests.size(); i++)
	{
			m_nests[i]->update(_player->getPosition(), _alienMissile);
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		if (m_nests[i]->_nestBulletVector.size() > 0)
		{
			for (int k = 0; k < m_nests[i]->_nestBulletVector.size(); k++)
			{
				m_nests[i]->_nestBulletVector[k]->seekerUpdate(_player->getPosition());

				if (m_nests[i]->_nestBulletVector[k]->lifeTime > 300)
				{
					m_nests[i]->_nestBulletVector.erase(m_nests[i]->_nestBulletVector.begin() + i);
					m_nests[i]->bulletCount--;
				}
			}
		}
	}

	for (int i = 0; i < _abductors.size(); i++)
	{
		for (int k = 0; k < m_astronauts.size(); k++)
		{
			//_abductors[i]->run(_abductors);
			_abductors[i]->movement(m_astronauts[0]->getPosition());
		}
	}

	checkHealth();
	CollisionManager();
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

void Play::checkHealth()
{
	for (int i = 0; i < _abductors.size(); i++)
	{
		if (_abductors[i]->getHealth() <= 0)
		{
			_abductors.erase(_abductors.begin() + i);
		}
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		if (m_nests[i]->getHealth() <= 0)
		{
			m_nests[i]->_nestBulletVector.clear();
			m_nests[i]->bulletCount = 0;
			m_nests.erase(m_nests.begin() + i);
		}
	}

	for (int i = 0; i < m_mutants.size(); i++)
	{
		if (m_mutants[i]->getHealth() <= 0)
		{
			m_mutants[i]->_mutantBulletVector.clear();
			m_mutants.erase(m_mutants.begin() + i);
		}
	}
}

void Play::updateCamera()
{
	_playerView = sf::View(sf::Vector2f(_player->getSprite().getPosition().x, gameHeight / 2), sf::Vector2f(600, gameHeight));
	game->window.setView(_playerView);
	draw();
	game->window.setView(_radarView);
	draw();
}

void Play::wrapAround()
{
	if (_player->getPosition().x > _rightSpawnBoundary)
	{
		float tempY = _player->getPosition().y;
		_player->setPosition(sf::Vector2f(_spawnLeft, tempY));
	}
	if (_player->getPosition().x <= _leftSpawnBoundary)
	{
		float tempY = _player->getPosition().y;
		_player->setPosition(sf::Vector2f(_spawnRight, tempY));
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

			if (event.key.code == sf::Keyboard::B)
			{
				if (_player->getBombCount() > 0)
				{
					for (int i = 0; i < m_mutants.size(); i++)
					{
						float playerMutantDist = sqrt(((_player->getPosition().x - m_mutants[i]->getPosition().x) * (_player->getPosition().x - m_mutants[i]->getPosition().x)) + ((_player->getPosition().y - m_mutants[i]->getPosition().y) * (_player->getPosition().y - m_mutants[i]->getPosition().y)));
						if (playerMutantDist < 600)
						{
							m_mutants[i]->takeDamage(2);
						}
					}

					for (int i = 0; i < m_nests.size(); i++)
					{
						float playerNestDist = sqrt(((_player->getPosition().x - m_nests[i]->getPosition().x) * (_player->getPosition().x - m_nests[i]->getPosition().x)) + ((_player->getPosition().y - m_nests[i]->getPosition().y) * (_player->getPosition().y - m_nests[i]->getPosition().y)));
						if (playerNestDist < 600)
						{
							m_nests[i]->takeDamage(2);
						}
					}

					for (int i = 0; i < _abductors.size(); i++)
					{
						float playerAbductorDist = sqrt(((_player->getPosition().x - _abductors[i]->getPosition().x) * (_player->getPosition().x - _abductors[i]->getPosition().x)) + ((_player->getPosition().y - _abductors[i]->getPosition().y) * (_player->getPosition().y - _abductors[i]->getPosition().y)));
						if (playerAbductorDist < 600)
						{
							_abductors[i]->takeDamage(2);
						}
					}
					_player->useBomb();
				}
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

		if (_player->getSprite().getPosition().y + _player->getSprite().getGlobalBounds().height / 2 < gameHeight)
		{
			if (event.key.code == sf::Keyboard::S)
			{
				_player->move(sf::Vector2f(0, 10), _dt);
			}
		}
		return;
	}
}

Play::~Play()
{


}





