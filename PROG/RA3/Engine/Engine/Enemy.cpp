#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::init(String textureName, Vector2f position, float speed)
{
	m_position = position;
	m_speed = speed;
	m_texture.loadFromFile(textureName);
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(m_position);
}

void Enemy::update(float dt)
{
	m_position.x += m_speed * dt;
	m_sprite.setPosition(m_position);
}

Sprite Enemy::getSprite()
{
	return m_sprite;
}
