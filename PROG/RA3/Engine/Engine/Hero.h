#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;

class Hero
{
public:
	Hero();
	~Hero();
	void init(String textureName, Vector2f position, float mass);
	void update(float dt);
	void jump(float velocity);
	Sprite getSprite();
private:
	Texture m_texture;
	Sprite m_sprite;
	Vector2f m_position;
	int jumpCount = 0, m_force;
	float m_mass;
	float m_velocity;
	const float m_gravity = 9.80;
	bool m_grounded;
};

