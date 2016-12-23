#include "../include/Player.h"

Player::Player(sf::Vector2f _Pos, sf::Vector2f _Vel, sf::Texture _Tex) : m_Pos(_Pos) , m_Vel(_Vel) , m_Tex(_Tex)
{
	m_Sprite.setTexture(m_Tex);
	m_Sprite.setPosition(m_Pos);
	m_Sprite.setOrigin(m_Sprite.getGlobalBounds().width / 2, m_Sprite.getGlobalBounds().height / 2);
	m_accel = sf::Vector2f(0, 0);
}

Player::~Player()
{


}


void Player::move(sf::Vector2f speed)
{
	if (m_Vel.x >=0)
	{
		m_Sprite.setScale(-1, 1);
		m_Sprite.setRotation(90);
	}
	else if (m_Vel.x <= 0)
	{
		m_Sprite.setScale(1, 1);
		m_Sprite.setRotation(-90);
	}

	m_Vel.x +=speed.x;
	m_Vel.y += speed.y;
	m_Pos += m_Vel;
	m_Sprite.setPosition(m_Pos);


}

sf::Sprite Player::getSprite()
{
	return m_Sprite;
}

