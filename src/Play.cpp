
#include "../include/Play.hpp"


Play::Play(Game* game)
{
	this->game = game;

	game->window.setFramerateLimit(60); 

	
	m_powerUpTex.loadFromFile("Assets/powerup.png");
	_playerTexture.loadFromFile("Assets/ship.png");
	_player = new Player(sf::Vector2f(1424,400),sf::Vector2f(0,0),_playerTexture);
	_nestTexture.loadFromFile("Assets/nest.png");
	_backgorundTexture.loadFromFile("Assets/back2.png");
	_astronautTexture.loadFromFile("Assets/astronaut.png");
	
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
	 m_nestCount = 1;
	 m_astronautCount = 6;
	 for (int i = 0; i < m_astronautCount; i++)
	 {
		 int _Ax = rand() % (5500 - 600 + 1) + 600;
		 Astronaut * _temp = new Astronaut(sf::Vector2f(_Ax, 690), sf::Vector2f(0, 0), _astronautTexture);
		 m_astronauts.push_back(_temp);
	 }

	 for (int i = 0; i < m_nestCount; i++)
	 {
		 _Nx = rand() % (5500 - 600 + 1) + 600;
		 _Ny = rand() % 700 + 1;
		 AlienNest * _Atemp = new AlienNest(sf::Vector2f(_Nx, _Ny), sf::Vector2f(0, 0), _nestTexture);
		 m_nests.push_back(_Atemp);
	 }

	 for (int i = 0; i < 2; i++)
	 {
		 _x = rand() % (5500 - 600 + 1) + 600;
		 _y = rand() % (600 - 100 + 1) + 100;
		 obstacles * _temp = new obstacles(sf::Vector2f(_x,_y),_asteroidTexture, _leftSpawnBoundary, _rightSpawnBoundary, _spawnLeft,_spawnRight);
		 m_obstacles.push_back(_temp);
	 }

	 m_powerUptimer = 1000;
	 m_screamBuffer.loadFromFile("Assets/scream.wav");
	 m_abductedSound.setBuffer(m_screamBuffer);
	 m_buffer.loadFromFile("Assets/laser.wav");
	 m_powerUpBuffer.loadFromFile("Assets/powerup.wav");
	 m_powerUpSound.setBuffer(m_powerUpBuffer);
	 m_explosionbuffer.loadFromFile("Assets/bomb.wav");
	 m_explosion.setBuffer(m_explosionbuffer);
	 m_playerFire.setBuffer(m_buffer);
	 if (!m_music.openFromFile("Assets/background.ogg"))
	 {
         // error...
	 }
	 else
	 {
		 m_music.setLoop(true);
		 m_music.play();
	 }

	 font.loadFromFile("Assets/arial.ttf");
	 m_round = 1;
	 m_roundText = sf::Text(" Round  : " +std::to_string(m_round), font);
	 m_roundText.setCharacterSize(30);
	 m_roundText.setStyle(sf::Text::Bold);
	 m_score = 0;
	 m_scoreText = sf::Text(" Score  : " + std::to_string(m_score), font);
	 m_scoreText.setCharacterSize(30);
	 m_scoreText.setStyle(sf::Text::Bold);
	 m_hyperJumpText = sf::Text(" Hyper jump available", font);
	 m_hyperJumpText.setCharacterSize(25);
	 m_hyperJumpText.setStyle(sf::Text::Bold);
	 m_health = sf::Text("Health : " + std::to_string(_player->getHealth()), font);
	 m_health.setCharacterSize(30);
	 m_health.setStyle(sf::Text::Bold);
	
} 


void Play::draw()
{	
	game->window.draw(_backgroundSprite);
	game->window.draw(_player->getSprite());

	for (int i = 0; i < _player->getBullets().size(); i++)
	{
		game->window.draw(_player->getBullets()[i]->getSprite());
	}
	game->window.draw(m_health);

	for (int i = 0; i < m_powerUps.size(); i++)
	{
		game->window.draw(m_powerUps[i]->getSprite());
	}
	

	for (int i = 0; i < m_astronauts.size(); i++)
	{
		game->window.draw(m_astronauts[i]->getSprite());
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
		if (m_mutants[i]->getBullets().size() > 0)
		{
			for (int k = 0; k < m_mutants[i]->getBullets().size(); k++)
			{
				game->window.draw(m_mutants[i]->getBullets()[k]->getSprite());
			}
		}
	}

	for (int i = 0; i < _abductors.size(); i++)
	{
		game->window.draw(_abductors[i]->getSprite());
	}
	
	for (int i = 0; i < m_nests.size(); i++)
	{
		game->window.draw(m_nests[i]->getSprite());
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		if (m_nests[i]->getBullets().size() > 0)
		{
			for (int k = 0; k < m_nests[i]->getBullets().size(); k++)
			{
				game->window.draw(m_nests[i]->getBullets()[k]->getSprite());
			}
		}
	}

	for (int i = 0; i < m_obstacles.size(); i++)
	{
		game->window.draw(m_obstacles[i]->getSprite());
	}
	for (int i = 0; i < _abductors.size(); i++)
	{
		if (_abductors[i]->getBullets().size() > 0)
		{
			for (int k = 0; k < _abductors[i]->getBullets().size(); k++)
			{
				game->window.draw(_abductors[i]->getBullets()[k]->getSprite());
			}
		}
	}
	

	game->window.draw(m_roundText);
	game->window.draw(m_scoreText);
	game->window.draw(m_hyperJumpText);

	return;
}

void Play::CollisionManager()
{

	for (int i = 0; i < m_nests.size(); i++)
	{
		for (int k = 0; k < m_nests[i]->getBullets().size(); k++)
		{
			if (_collisionManager.collision(m_nests[i]->getBullets()[k]->getCollisionRect(),_player->getCollisionRect()))
			{
				m_explosion.play();
				m_nests[i]->getBullets().erase(m_nests[i]->getBullets().begin() + i);
				m_nests[i]->setBulletCount(m_nests[i]->getBulletCount() -1);
		
				if (_player->getHealth() > 0)
				{
					_player->takeDamage(30);
					m_health = sf::Text("Health : " + std::to_string(_player->getHealth()), font);
				}
			}
		}
	}

	for (int i = 0; i < m_nests.size(); i++)
	{
		for (int k = 0; k < m_obstacles.size(); k++)
		{
			if (_collisionManager.collision(m_nests[i]->getCollisionRect(), m_obstacles[k]->getCollisionRect()))
			{
				m_explosion.play();
				if (m_nests[i]->getHealth() > 0)
				{
					m_nests[i]->takeDamage(2);
				}
			}

		}

	}
	for (int i = 0; i < m_mutants.size(); i++)
	{
		for (int k = 0; k < m_obstacles.size(); k++)
		{
			if (_collisionManager.collision(m_mutants[i]->getCollisionRect(), m_obstacles[k]->getCollisionRect()))
			{
				m_explosion.play();
				if (m_mutants[i]->getHealth() > 0)
				{
					m_mutants[i]->takeDamage(2);
				}
			}

		}

	}
	
		for (int k = 0; k < m_obstacles.size(); k++)
		{
			if (_collisionManager.collision(_player->getCollisionRect(), m_obstacles[k]->getCollisionRect()))
			{
				m_explosion.play();
				if (_player->getHealth() > 0)
				{
					_player->takeDamage(100);
				}
			}
	}

	for (int i = 0; i < _abductors.size(); i++)
	{
		for (int k = 0; k < m_obstacles.size(); k++)
		{
			if (_collisionManager.collision(_abductors[i]->getCollisionRect(), m_obstacles[k]->getCollisionRect()))
			{
				m_explosion.play();
				if (_abductors[i]->getHealth() > 0)
				{
					_abductors[i]->takeDamage(2);
				}
			}
		}
	}

	for (int i = 0; i < m_mutants.size(); i++)
	{
		for (int k = 0; k < m_mutants[i]->getBullets().size(); k++)
		{
			if (_collisionManager.collision(m_mutants[i]->getBullets()[k]->getCollisionRect(), _player->getCollisionRect()))
			{
				m_explosion.play();
				if (_player->getHealth() > 0)
				{
					_player->takeDamage(20);
					m_health = sf::Text("Health : " + std::to_string(_player->getHealth()), font);
				}
				m_mutants[i]->getBullets().erase(m_mutants[i]->getBullets().begin() + k);
			}
		}
	}


	for (int i = 0; i < _abductors.size(); i++)
	{
		for (int k = 0; k < _abductors[i]->getBullets().size(); k++)
		{
			if (_collisionManager.collision(_abductors[i]->getBullets()[k]->getCollisionRect(), _player->getCollisionRect()))
			{
				m_explosion.play();
				
				if (_player->getHealth() > 0)
				{
					if (_player->getInvincible() == false)
					{
						_player->takeDamage(10);
						m_health = sf::Text("Health : " + std::to_string(_player->getHealth()), font);
					}
				}
				_abductors[i]->getBullets().erase(_abductors[i]->getBullets().begin() + k);
				
			}
			
		}
	}

	for (int k = 0; k < m_mutants.size(); k++)
	{
		for (int i = 0; i < _player->getBullets().size(); i++)
		{

			if (_collisionManager.collision( _player->getBullets()[i]->getCollisionRect(), m_mutants[k]->getCollisionRect()))
			{
				
				if (m_mutants[k]->getHealth() > 0)
				{
					m_mutants[k]->takeDamage(1);
					increaseScore();
				}
				
				_player->getBullets().erase(_player->getBullets().begin() + i);
			}
		}
	}

	for (int k = 0; k < m_nests.size(); k++)
	{
		for (int i = 0; i < _player->getBullets().size(); i++)
		{

			if (_collisionManager.collision(_player->getBullets()[i]->getCollisionRect(), m_nests[k]->getCollisionRect()))
			{
				if (m_nests[k]->getHealth() > 0)
				{
					m_nests[k]->takeDamage(1);
					increaseScore();
				}
				_player->getBullets().erase(_player->getBullets().begin() + i);
			}
		}
	}

	for (int k = 0; k < _abductors.size(); k++)
	{
		for (int i = 0; i < _player->getBullets().size(); i++)
		{
			if (_collisionManager.collision(_player->getBullets()[i]->getCollisionRect(), _abductors[k]->getCollisionRect()))
			{
				m_explosion.play();
				if (_abductors[k]->getHealth() > 0)
				{
					_abductors[k]->setAbducting(false);

					for (int j = 0; j < m_astronauts.size(); j++)
					{
						if (_collisionManager.collision(_abductors[k]->getCollisionRect(), m_astronauts[j]->getCollisionRect()))
						{
							m_astronauts[j]->setAbducted(false);
						}
					}
					_abductors[k]->takeDamage(1);
					increaseScore();
				}
			
				_player->getBullets().erase(_player->getBullets().begin() + i);
			}
		}
	}
}
void Play::updateRounds()
{
	if (m_nests.size() ==0 && _abductors.size() ==0 && m_mutants.size() ==0)
	{
		increaseRound();
		for (int i = 0; i < m_nestCount; i++)
		{
			int _Nx = rand() % (5500 - 600 + 1) + 600;
			int _Ny = rand() % 700 + 1;
			AlienNest * _Atemp = new AlienNest(sf::Vector2f(_Nx, _Ny), sf::Vector2f(0, 0), _nestTexture);
			m_nests.push_back(_Atemp);
		}
	}
}
void Play::update()
{
	_dt = _clock.restart().asSeconds();

	updateCamera();
	wrapAround();
	_player->update(_dt);
	updatePowerUps();
	updateRounds();
	
	m_roundText.setPosition(sf::Vector2f(_playerView.getCenter().x + _playerView.getSize().x/4.5,_playerView.getCenter().y - _playerView.getSize().y / 2));
	m_scoreText.setPosition(sf::Vector2f(_playerView.getCenter().x - _playerView.getSize().x / 2, _playerView.getCenter().y - _playerView.getSize().y / 2));
	m_hyperJumpText.setPosition(sf::Vector2f(_playerView.getCenter().x - +_playerView.getSize().x / 4.5, _playerView.getCenter().y + _playerView.getSize().y / 4.5));
	m_health.setPosition(sf::Vector2f(_playerView.getCenter().x - +_playerView.getSize().x / 6.5, _playerView.getCenter().y + _playerView.getSize().y / 3.5));


	for (int i = 0; i < _player->getBullets().size(); i++)
	{
			_player->getBullets()[i]->update();
	}


	for (int i = 0; i < m_nests.size(); i++)
	{
		if (m_nests[i]->getAbductorSpawnTimer() > 150 && m_nests[i]->getAbductorCount() < 10)
		{
			Abductor* _temp = new Abductor(sf::Vector2f(m_nests[i]->getPosition().x, m_nests[i]->getPosition().y), sf::Vector2f(0, 0), _abtuctorTexture,_playerBullet);
			_abductors.push_back(_temp);
			m_nests[i]->setAbductorSpawnTimer(0);
			m_nests[i]->setAbductorCount(m_nests[i]->getAbductorCount() + 1);
		}
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
		m_mutants[i]->setindex(i);
		m_mutants[i]->computeAlignment(m_mutants);
		m_mutants[i]->computeCohesion(m_mutants);
		m_mutants[i]->computeSeparation(m_mutants);
		m_mutants[i]->swarm(m_mutants,_player->getPosition());
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
		if (m_mutants[i]->getBullets().size() > 0)
		{
			for (int k = 0; k < m_mutants[i]->getBullets().size(); k++)
			{
				m_mutants[i]->getBullets()[k]->mutantUpdate(_player->getPosition());
				if (m_mutants[i]->getBullets()[k]->getLifeTime() >300)
				{
					m_mutants[i]->getBullets().erase(m_mutants[i]->getBullets().begin() + k);
				}
			}
		}
	}

	for (int i = 0; i < _abductors.size(); i++)
	{
		if (_abductors[i]->getBullets().size() > 0)
		{
			for (int k = 0; k < _abductors[i]->getBullets().size(); k++)
			{
				_abductors[i]->getBullets()[k]->mutantUpdate(_player->getPosition());
				if (_abductors[i]->getBullets()[k]->getLifeTime() >300)
				{
					_abductors[i]->getBullets().erase(_abductors[i]->getBullets().begin() + k);
				}
			}
		}
	}
	for (int i = 0; i < _abductors.size(); i++)
	{
		_abductors[i]->movement(_player->getPosition());
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
		if (m_nests[i]->getBullets().size() > 0)
		{
			for (int k = 0; k < m_nests[i]->getBullets().size(); k++)
			{
				m_nests[i]->getBullets()[k]->seekerUpdate(_player->getPosition());

				if (m_nests[i]->getBullets()[k]->getLifeTime() > 300)
				{
					m_nests[i]->getBullets().erase(m_nests[i]->getBullets().begin() + i);
					m_nests[i]->setBulletCount(m_nests[i]->getBulletCount()-1);
				}
			}
		}
	}


	


	for (int t1 = _player->getBullets().size()-1; t1>=0; --t1)
	{
		if (_player->getBullets()[t1]->getLifeTime() > 300)
		{
			_player->getBullets().erase(_player->getBullets().begin() + t1);
		}
	}
	
	for (int i = 0; i < _abductors.size(); i++)
	{
		for (int k = 0; k < m_astronauts.size(); k++)
		{	
			if (_collisionManager.collision(m_astronauts[k]->getSeekRect(), _abductors[i]->getCollisionRect()) == false)
			{
				_abductors[i]->setIndex(i);
				_abductors[i]->computeAlignment(_abductors);
				_abductors[i]->computeCohesion(_abductors);
				_abductors[i]->computeSeparation(_abductors);

				_abductors[i]->wander(_abductors);
			}
			if ((_collisionManager.collision(m_astronauts[k]->getSeekRect(), _abductors[i]->getCollisionRect()) == true))
			{
				
				if (m_astronauts[k]->getAbducted() == false)
				{
					_abductors[i]->seek(m_astronauts[k]->getPosition());
				}
				if (_collisionManager.collision(_abductors[i]->getCollisionRect(), m_astronauts[k]->getCollisionRect()))
				{
					if (m_astronauts[k]->getAbducted() == false)
					{
						m_abductedSound.play();
					}
					_abductors[i]->abducting();
					m_astronauts[k]->abducted(_abductors[i]->getPosition());
				}
			}			
		}
	}

	checkHealth();
	CollisionManager();
	
	game->window.display();
	
	activateGameOverState();
	
	return;
}

void Play::activateGameOverState()
{
	if (_player->getAlive() == false || m_astronauts.size() <=0)
	{
		m_music.stop();
		m_playerFire.stop();
		m_explosion.stop();
		m_powerUpSound.stop();
		m_abductedSound.stop();
		this->game->changeState(new GameOver(this->game,m_score));
	}
}

void Play::updatePowerUps()
{
	for (int i = 0; i < m_powerUps.size(); i++)
	{
		m_powerUps[i]->update();
	}

	for (int i = 0; i < m_powerUps.size(); i++)
	{
		if (_collisionManager.collision(_player->getCollisionRect(), m_powerUps[i]->getCollisionRect()) == true)
		{
			m_powerUpSound.play();
			if (m_powerUps[i]->getType() == PowerUPType::Speed)
			{
				_player->setFastAccel(true);
				m_powerUps.erase(m_powerUps.begin() + i);
			}
			else if (m_powerUps[i]->getType() == PowerUPType::INVINCIBILITY)
			{
				_player->setInvincible(true);
				m_powerUps.erase(m_powerUps.begin() + i);

			}
			else if (m_powerUps[i]->getType() == PowerUPType::TELEPORT)
			{
				_player->setCanHyperjump(true);
				m_hyperJumpText = sf::Text("Hyperjump Ready", font);
				m_hyperJumpText.setCharacterSize(25);
				m_powerUps.erase(m_powerUps.begin() + i);
			}
		}
	}

	m_powerUptimer--;

	if (m_powerUptimer <= 0)
	{
		if (m_powerUps.size() != 0)
		{
			m_powerUps.pop_back();
		}
		int  _x = rand() % (5500 - 400 + 1) + 400;
		int  _y = rand() % (600 - 100 + 1) + 100;
		int type = rand() % (2 - 0 + 1) + 0;
		PowerUp* _temp = new PowerUp(sf::Vector2f(_x, _y), m_powerUpTex,static_cast<PowerUPType>(type));
		m_powerUps.push_back(_temp);
		m_powerUptimer = 1000;
	}
}

void Play::checkHealth()
{
	if (_player->getHealth() <=0)
	{
		_player->setAlive(false);
	}
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
			
			m_nests.erase(m_nests.begin() + i);
		}
	}

	for (int i = 0; i < m_mutants.size(); i++)
	{
		if (m_mutants[i]->getHealth() <= 0)
		{
			m_mutants[i]->getBullets().clear();
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

void Play::increaseRound()
{
	m_round++;
	if (m_round > 5)
	{
		m_nestCount++;
		
	}
	m_roundText = sf::Text(" Round  : " + std::to_string(m_round), font);
}

void Play::increaseScore()
{
	m_score++;
	m_scoreText = sf::Text(" Score  : " + std::to_string(m_score), font);
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
			if (event.key.code == sf::Keyboard::Space)
			{
				m_playerFire.play();
				if (_player->getDirection() == false)
				{
					_player->createBullet(_playerBullet, 10);
				}
				else
				{
					_player->createBullet(_playerBullet, -10);
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			{
				_player->hyperJump();
				_player->setCanHyperjump(false);
				m_hyperJumpText = sf::Text("Hyper jump unavailable", font);
				m_hyperJumpText.setCharacterSize(25);
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





