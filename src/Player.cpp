#include "../include/Player.h"

Player::Player(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_Pos(_Pos) , m_Vel(_Vel) , m_Tex(_Tex)
{
	m_Sprite.setTexture(m_Tex);
	m_Sprite.setPosition(m_Pos);
	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);
	m_accel = sf::Vector2f(0, 0);
	m_decelerate = false;
	m_Sprite.setRotation(90);
	m_direction = false;
}

Player::~Player()
{


}


void Player::move(sf::Vector2f speed)
{
	if (m_accel.x < 1)
	{
		m_accel.x += 0.01f;
	}

	if (speed.x >0 && speed.y ==0)
	{
		m_Vel.x = 0;
		m_Sprite.setScale(-1, 1);
		m_Vel.x += speed.x;
		m_Sprite.setRotation(90);
	}
	else if (speed.x < 0 && speed.y ==0)
	{
		m_Vel.x = 0;
		m_Sprite.setScale(1, 1);
		m_Vel.x += speed.x;
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


	m_Pos.x += m_Vel.x * m_accel.x;
	m_Pos.y += m_Vel.y;
	m_Sprite.setPosition(m_Pos);

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
void Player::update()
{
	if (m_decelerate ==true && m_accel.x > 0)
	{
		m_accel.x -= 0.01f;
		m_Pos.x += m_Vel.x * m_accel.x;
		if (m_accel.x < 0 )
		{
			m_accel = sf::Vector2f(0, 0);
		}
		m_Sprite.setPosition(m_Pos);
	}	
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

