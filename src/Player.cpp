#include "../include/Player.h"
#include <iostream>
Player::Player(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_Pos(_Pos), m_Vel(_Vel), m_Tex(_Tex)
{
	m_Sprite.setTexture(m_Tex);
	m_Sprite.setPosition(m_Pos);
	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);
	m_accel = sf::Vector2f(0, 0);
	m_decelerate = false;
	m_Sprite.setRotation(90);
	m_direction = false;
	m_friction = 0.997f;
	m_maxAcceleration = 100;
	m_canHyperJump = true;
	collisionBox =  sf::RectangleShape(sf::Vector2f(m_Tex.getSize().x, m_Tex.getSize().y));
}
Player::~Player()
{


}


void Player::move(sf::Vector2f speed , float _dt)
{
	if (m_accel.x < m_maxAcceleration && m_decelerate == false)
	{
		m_accel.x += 5;
	}
	if (m_direction == true && m_Vel.x > 0)
	{
		m_accel.x = 0;
	}
	else if (m_direction == false && m_Vel.x < 0)
	{
		m_accel.x = 0;
	}

	if (speed.x >0 && speed.y ==0)
	{
		m_Vel.x = 0;
		m_Sprite.setScale(-1, 1);
		m_Vel.x = speed.x * m_accel.x * _dt;
		m_Sprite.setRotation(90);
	}
	
	 if (speed.x < 0 && speed.y ==0)
	{
		m_Vel.x = 0;
	
		m_Sprite.setScale(1, 1);
		m_Vel.x = speed.x * m_accel.x * _dt;
		m_Sprite.setRotation(-90);
	}
	if (speed.y >= 0)
	{
		
		m_Vel.y = 0;
		m_Vel.y += speed.y;
	}
	else if (speed.y <= 0)
	{
		m_Vel.y = 0;
		m_Vel.y += speed.y;
	}


	m_Pos.x += m_Vel.x;
	m_Pos.y += m_Vel.y;
	m_Sprite.setPosition(m_Pos);
	collisionBox.setPosition(m_Pos.x, m_Pos.y);
	std::cout << "vel : " << m_Vel.x << " accel : " << m_accel.x << std::endl;
}

void Player::setdirection(bool value)
{
	m_direction = value;
}
bool Player::getDirection()
{
	return m_direction;
}

bool Player::isdecelerating()
{

	return m_decelerate;
}
void Player::setdecelerating(bool value )
{
	m_decelerate = value;
}

void Player::handleInput(float _dt)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (m_Pos.y - m_Sprite.getGlobalBounds().height / 2 > 0)
		{
			move(sf::Vector2f(0, -2), _dt);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move(sf::Vector2f(2, 0), _dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (m_Pos.y + m_Sprite.getGlobalBounds().height / 2 < 1056)// +_player->getSprite().getGlobalBounds().height / 2 < gameHeight)
		{
			move(sf::Vector2f(0, 2), _dt);
		
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move(sf::Vector2f(-2, 0), _dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		if (m_canHyperJump)
		{
			spawn(sf::Vector2f((rand() % 2000 - 1000 + 1000), rand() % 900 - 100 + 100));
			m_canHyperJump = false;
		}
	}
}


void Player::spawn(sf::Vector2f _newPos)
{
	m_Pos = _newPos;
}
sf::RectangleShape Player::getCollisionRect()
{
	return collisionBox;
}

void Player::update(float _dt)
{
	handleInput(_dt);

	if (m_decelerate ==true && m_Vel.x >0)
	{
		m_accel.x += -0.5;
		m_Vel.x = m_accel.x * _dt;
		m_Vel.x *= m_friction;
		m_Pos.x += m_Vel.x;
		if (m_accel.x < 0 )
		{
			m_accel = sf::Vector2f(0, 0);
		}
		m_Sprite.setPosition(m_Pos);
		collisionBox.setPosition(m_Pos.x, m_Pos.y);
	}	
	 if (m_decelerate == true && m_Vel.x < 0)
	{
		m_accel.x += -0.5;
		m_Vel.x = -m_accel.x * _dt;
		m_Vel.x *= m_friction;
		m_Pos.x += m_Vel.x;
		if (m_accel.x < 0)
		{
			m_accel = sf::Vector2f(0, 0);
		}
		m_Sprite.setPosition(m_Pos);
		collisionBox.setPosition(m_Pos.x, m_Pos.y);
	}
	// std::cout << "velocity : " << m_Vel.x << " acceleration : " << m_accel.x << " speed :  std::endl;
}
sf::Vector2f Player::getPosition()
{
	return m_Pos;
}
void Player::setPosition(sf::Vector2f _tempPos)
{
	m_Pos = _tempPos;
}

sf::Sprite Player::getSprite()
{
	return m_Sprite;
}

