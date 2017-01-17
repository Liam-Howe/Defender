

#include "../include/Abductor.h"

Abductor::Abductor(sf::Vector2f _pos, sf::Vector2f _vel, sf::Texture _tex) : m_pos(_pos) , m_vel(_vel),m_tex(_tex)
{
	m_sprite.setTexture(m_tex);
	m_sprite.setPosition(m_pos);
	maxSpeed = 3.5;
	maxForce = 0.5;
	m_vel = sf::Vector2f(rand() % 3 - 2, rand() % 3 - 2);
	m_abducting = false;
	health = 1;

	collisionBox =  sf::RectangleShape(sf::Vector2f(m_sprite.getGlobalBounds().width, m_sprite.getGlobalBounds().width));
	collisionBox.setPosition(m_pos);
}
Abductor::~Abductor()
{

}
void Abductor::update()
{
	m_acceleration = mulScalar(.4,m_acceleration);
	m_vel = addVector(m_acceleration, m_vel);
	m_vel = limit(maxSpeed, m_vel);
	m_pos = addVector(m_vel, m_pos);
	m_acceleration = mulScalar(0, m_acceleration);
	m_sprite.setPosition(m_pos);
	collisionBox.setPosition(m_pos.x, m_pos.y);
}
void Abductor::flock(std::vector<Abductor*>_abductor)
{

	sf::Vector2f _alignment = alignment(_abductor);
	sf::Vector2f _seperation = seperation(_abductor);
	sf::Vector2f _cohesion = cohesion(_abductor);

	_alignment = mulScalar(1.5,_alignment);
	_seperation = mulScalar(1.0,_seperation);
	_cohesion = mulScalar(1.0,_cohesion);

	applyForce(_alignment);
	applyForce(_seperation);
	applyForce(_cohesion);

}
void Abductor::applyForce(sf::Vector2f force)
{
	addVector(force, m_acceleration);
}

void Abductor::setAbducting(bool value)
{
	m_abducting = value;
}

sf::Vector2f Abductor::getVelocity()
{
	return m_vel;
}
sf::Vector2f Abductor::mulScalar(float s,sf::Vector2f _currentVector)
{

	_currentVector.x *= s;
	_currentVector.y *= s;
	return _currentVector;
}

sf::Vector2f Abductor::cohesion(std::vector<Abductor*>_abductor)
{
	float neghbourDist = 50;
	sf::Vector2f sum(0, 0);
	int count = 0;
	for (int i = 0; i < _abductor.size(); i++)
	{
		float d = sqrt(((m_pos.x - _abductor[i]->getPosition().x) * (m_pos.x - _abductor[i]->getPosition().x)) + ((m_pos.y - _abductor[i]->getPosition().y) * (m_pos.y - _abductor[i]->getPosition().y)));
		if ((d > 0) && (d < neghbourDist))
		{
			sum = addVector(_abductor[i]->getPosition(), sum);
			count++;
		}
	}
	if (count > 0)
	{
		sum = divScalar(count,sum);
		return flockSeek(sum);
	}
	else
	{
		sf::Vector2f temp(0, 0);
		return temp;
	}
}

sf::Vector2f Abductor::alignment(std::vector<Abductor*>_abductor)
{
	float neighbordist = 50;
	sum = sf::Vector2f(0, 0);
	int count = 0;
	for (int i = 0; i < _abductor.size(); i++)
	{
		float d = sqrt(((m_pos.x - _abductor[i]->getPosition().x) * (m_pos.x - _abductor[i]->getPosition().x)) + ((m_pos.y - _abductor[i]->getPosition().y) * (m_pos.y - _abductor[i]->getPosition().y)));
		if (d > 0 && (d < neighbordist))
		{
			sum = addVector(_abductor[i]->getVelocity(), sum);
			count++;
		}
	}
	
	if (count > 0)
	{
		sum = divScalar((float)count,sum);
		Normalise(sum);
		sum = mulScalar(maxSpeed,sum);
		sf::Vector2f steer;
		steer = subTwoVector(sum, m_vel);
		steer = limit(maxForce,steer);
		return steer;
	}
	else
	{
		sf::Vector2f temp(0, 0);
		return temp;
	}
}

sf::Vector2f Abductor::limit(double max, sf::Vector2f _currentVector)
{
	double size = sqrt(_currentVector.x * _currentVector.x + _currentVector.y * _currentVector.y);

	if (size > max)
	{
		_currentVector.x = _currentVector.x / size;
		_currentVector.y = _currentVector.y / size;
	}
	return _currentVector;
}
sf::Vector2f Abductor::seperation(std::vector<Abductor*>_abductor)
{
	float desiredseparation = 20;
	steer = sf::Vector2f(0, 0);
	int count = 0;
	for (int i = 0; i < _abductor.size(); i++)
	{
		float d = sqrt(((m_pos.x - _abductor[i]->getPosition().x) * (m_pos.x - _abductor[i]->getPosition().x)) + ((m_pos.y - _abductor[i]->getPosition().y) * (m_pos.y - _abductor[i]->getPosition().y)));
		if ((d > 0) && (d < desiredseparation))
		{
			diff = sf::Vector2f(0, 0);
			diff = subTwoVector(m_pos, _abductor[i]->getPosition());
			Normalise(diff);
			diff = divScalar(d, diff);
			steer = addVector(diff, steer);
			count++;
		}
	}
	return steer;
}
sf::Vector2f Abductor::subTwoVector(sf::Vector2f _currentVector,sf::Vector2f a_pos)
{
	_currentVector.x -= a_pos.x;
	_currentVector.y -= a_pos.y;
	return _currentVector;
}

sf::Vector2f Abductor::divScalar(float d,sf::Vector2f _currentVector)
{
	_currentVector.x /= d;
	_currentVector.y /= d;
	return _currentVector;
}
sf::Vector2f Abductor::addVector(sf::Vector2f v , sf::Vector2f _currentVector)
{
	_currentVector.x += v.x;
	_currentVector.y += v.y;
	return _currentVector;
}


void Abductor::movement(sf::Vector2f targetPos)
{
	float Dist = sqrt(((m_pos.x - targetPos.x) * (m_pos.x - targetPos.x)) + ((m_pos.y - targetPos.y) * (m_pos.y - targetPos.y)));

	//if (Dist < 700 && m_following == false)
	//{
	//	m_seek = true;
	//	m_following = true;
	//}

	//if (Dist < 300)
	//{
	//	m_seek = false;
	//}

	//if (m_seek == true && m_abducting == false)
	//{
	if(m_abducting == false)
	{
		seek(targetPos);
	}

	//else if (m_seek == false && m_abducting == false)
//	{
		//		wander();
	//}

	if (m_abducting == true)
	{
		m_pos.y = m_pos.y - 0.5;
	
	}

	m_sprite.setPosition(m_pos);
	collisionBox.setPosition(m_pos);
}

sf::Vector2f Abductor::subVector(sf::Vector2f _pos ,sf::Vector2f _currentVector)
{
	_currentVector.x -= _pos.x;
	_currentVector.y -= _pos.y;
	return _currentVector;
}

int Abductor::getHealth()
{
	return health;
}

void Abductor::takeDamage(int value)
{
	health = health - value;
}

sf::Vector2f Abductor::flockSeek(sf::Vector2f v)
{

	sf::Vector2f desired;
	desired = subVector(v,desired);  // A vector pointing from the location to the target
						   // Normalize desired and scale to maximum speed
	Normalise(desired);
	desired = mulScalar(maxSpeed,desired);
	// Steering = Desired minus Velocity
	m_acceleration = subTwoVector(desired, m_vel);
	m_acceleration = limit(maxForce,m_acceleration);  // Limit to maximum steering force
	return m_acceleration;
}
sf::RectangleShape Abductor::getCollisionRect()
{
	return collisionBox;
}

void Abductor::seek(sf::Vector2f targetPos)
{
	m_vel.x = targetPos.x - m_pos.x;
	m_vel.y = targetPos.y - m_pos.y;
	m_vel = Normalise(m_vel);
	m_pos += m_vel;
	m_sprite.setPosition(m_pos);
	collisionBox.setPosition(m_pos);
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

void Abductor::run(std::vector<Abductor*>_abductors)
{
	for (int i = 0; i < _abductors.size(); i++)
	{
		if (sqrt(((m_pos.x - _abductors[i]->getPosition().x) * (m_pos.x - _abductors[i]->getPosition().x)) + ((m_pos.y - _abductors[i]->getPosition().y) * (m_pos.y - _abductors[i]->getPosition().y))) < 100)
		{
			flock(_abductors);
		}
	}
	update();
}