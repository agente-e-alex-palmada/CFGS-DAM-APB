#include "Rocket.h"

Rocket::Rocket()
{
}

Rocket::~Rocket()
{
}

void Rocket::init(std::string textureName, sf::Vector2f position, float speed)
{
	m_position = position;
	m_speed = speed;
	m_texture.loadFromFile(textureName);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
}

void Rocket::update(float dt)
{
	m_sprite.move(m_speed * dt, 0);
}

Sprite Rocket::getSprite()
{
	return m_sprite;
}
