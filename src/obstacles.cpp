
#include "../include/obstacles.h"

obstacles::obstacles(sf::Vector2f _pos, sf::Texture _tex,  float leftSpawnBoundary, float rightspawnBoundary, float leftSpawn, float rightSpawn) : m_pos(_pos) , m_tex(_tex), m_leftSpawnBoundary(leftSpawnBoundary),
    m_rightSpawnBoundary(rightspawnBoundary),
	m_leftSpawn(leftSpawn),
	m_rightSpawn(rightSpawn)
{
	m_Sprite.setTexture(m_tex);
	m_Sprite.setPosition(m_pos);
	m_Vel.x = rand() % 2+ (-2);
	m_Vel.y = rand() % 2 + (-2);
	m_rectangle = sf::RectangleShape(sf::Vector2f(m_Sprite.getGlobalBounds().width, m_Sprite.getGlobalBounds().height));
	m_rectangle.setPosition(m_pos);
}

obstacles::~obstacles()
{


}
void obstacles::update()
{
	//m_Vel = sf::Vector2f(0, -1);
	m_pos += m_Vel;
	m_Sprite.setPosition(m_pos);
	m_rectangle.setPosition(m_pos);

	if (m_pos.y - m_Sprite.getGlobalBounds().height/2 < 0)
	{
		m_Vel = sf::Vector2f(m_Vel.x, - m_Vel.y);
	}
	if (m_pos.y + m_Sprite.getGlobalBounds().height / 2 > 690)
	{
		m_Vel = sf::Vector2f(m_Vel.x, -m_Vel.y);
	}
	if (m_pos.x + m_Sprite.getGlobalBounds().width / 2 > m_rightSpawnBoundary)
	{
		m_pos.x = m_leftSpawn;
	}
	if (m_pos.x - m_Sprite.getGlobalBounds().width / 2 < m_leftSpawnBoundary)
	{
		m_pos.x = m_rightSpawn;
	}
	
}
sf::RectangleShape obstacles::getCollisionRect()
{
	return m_rectangle;
}
sf::Sprite obstacles::getSprite()
{
	return m_Sprite;
}