
#include "../include/obstacles.h""

obstacles::obstacles(sf::Vector2f _pos, sf::Texture _tex, sf::Vector2f _vel, float _gameHeight, float _gameWidth) : m_pos(_pos) , m_tex(_tex), m_Vel(_vel) , m_gameHeight(_gameHeight), m_gameWidth(_gameWidth)
{
	m_Sprite.setTexture(m_tex);
	m_Sprite.setPosition(m_pos);
}

obstacles::~obstacles()
{


}
void obstacles::update()
{
	//m_Vel = sf::Vector2f(0, -1);
	m_pos += m_Vel;
	m_Sprite.setPosition(m_pos);


	if (m_pos.y - m_Sprite.getGlobalBounds().height/2 < 0)
	{
		m_Vel = sf::Vector2f(0,1);
	}
	if (m_pos.y + m_Sprite.getGlobalBounds().height / 2 > m_gameHeight)
	{
		m_Vel = sf::Vector2f(0, -1);
	}
	if (m_pos.x + m_Sprite.getGlobalBounds().width / 2 > m_gameWidth)
	{
		m_Vel = sf::Vector2f(-1, -0);
	}
	if (m_pos.x - m_Sprite.getGlobalBounds().width / 2 < 0)
	{
		m_Vel = sf::Vector2f(1, 0);
	}

}
sf::Sprite obstacles::getSprite()
{
	return m_Sprite;
}