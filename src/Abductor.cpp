

#include "../include/Abductor.h"

Abductor::Abductor(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex) : m_pos(_pos) , m_vel(_vel),m_tex(_tex)
{
	m_sprite.setTexture(m_tex);
	m_sprite.setPosition(m_pos);
}
Abductor::~Abductor()
{

}
void Abductor::update()
{

}
sf::Vector2f Abductor::flock(Abductor& _abductor)
{

	sf::Vector2f _alignment = alignment(_abductor);
	sf::Vector2f _seperation = seperation(_abductor);
	sf::Vector2f _cohesion = cohesion(_abductor);



}
sf::Vector2f Abductor::getVelocity()
{
	return m_vel;
}
sf::Vector2f Abductor::mulScalar(float s)
{

	sum.x *= s;
	sum.y *= s;
	return sum;
}



sf::Vector2f Abductor::alignment(Abductor&_abductor)
{
	float neighbordist = 50;
	sum = sf::Vector2f(0, 0);
	int count = 0;

	float d = sqrt(((m_pos.x - _abductor.getPosition().x) * (m_pos.x - _abductor.getPosition().x)) + ((m_pos.y - _abductor.getPosition().y) * (m_pos.y - _abductor.getPosition().y)));
	if (d > 0 && (d < neighbordist))
	{
		sum = addVector(_abductor.getVelocity());
		count++;
	}
	if (count > 0)
	{
		sum = divScalar((float)count);
		Normalise(sum);
		sum = mulScalar(maxSpeed);
		sf::Vector2f steer;
		steer = subTwoVector(sum, m_vel);
		steer = limit(maxForce);


	}
}
sf::Vector2f Abductor::limit(double max)
{
	double size = magnitude();

	if (size > max)
	{
		set(x / size, y / size);
	}
	return steer;
}
sf::Vector2f Abductor::seperation(Abductor& _abductor)
{
	float desiredseparation = 20;
	steer = sf::Vector2f(0, 0);
	int count = 0;

	float d = sqrt(((m_pos.x - _abductor.getPosition().x) * (m_pos.x - _abductor.getPosition().x)) + ((m_pos.y - _abductor.getPosition().y) * (m_pos.y - _abductor.getPosition().y)));
	if (d > 0 && (d < desiredseparation))
	{
		diff = sf::Vector2f(0, 0);
		diff = subTwoVector(m_pos, _abductor.getPosition());
		Normalise(diff);
		diff = divScalar(d);
		steer = addVector(diff);

	}
	return steer;
}
sf::Vector2f Abductor::subTwoVector(sf::Vector2f m_pos,sf::Vector2f a_pos)
{
	m_pos.x -= a_pos.x;
	m_pos.y -= a_pos.y;
}

sf::Vector2f Abductor::divScalar(float d)
{
	diff.x /= d;
	diff.y /= d;

}
sf::Vector2f Abductor::addVector(sf::Vector2f v)
{
	steer.x += v.x;
	steer.y += v.y;
}
sf::Vector2f Abductor::cohesion(Abductor _abductor)
{

	
}

void Abductor::movement(sf::Vector2f targetPos)
{
	float Dist = sqrt(((m_pos.x - targetPos.x) * (m_pos.x - targetPos.x)) + ((m_pos.y - targetPos.y) * (m_pos.y - targetPos.y)));

	if (Dist > 100)
	{
		m_seek = true;
	}
	if (Dist < 300)
	{
		m_seek = false;
	}
}

void Abductor::seek(sf::Vector2f targetPos)
{
	m_vel.x = targetPos.x - m_pos.x;
	m_vel.y = targetPos.y - m_pos.y;
	m_vel = Normalise(m_vel);
	m_pos += m_vel;
	m_sprite.setPosition(m_pos);

}
sf::Vector2f Abductor::Normalise(sf::Vector2f velocity)
{
	float length;
	length = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
	velocity = velocity / length;
	return velocity;
}
sf::Vector2f Abductor::getPosition()
{
	return m_pos;
}
void Abductor::setPosition(sf::Vector2f _tempPos)
{
	m_pos = _tempPos;
}

sf::Sprite Abductor::getSprite()
{
	return m_sprite;
}