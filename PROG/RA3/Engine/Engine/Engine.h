#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <vector>
#include "Hero.h"
#include "Enemy.h"
#include "Rocket.h"

using namespace std;

class Engine
{
public:
	int run();
	Engine();
	~Engine();

private:

// Window creation
	Vector2f viewSize;
	VideoMode vm;
	RenderWindow window;

// Textures and sprites
	Texture skyTexture;
	Sprite skySprite;
	Texture bgTexture;
	Sprite bgSprite;

// Texts for the game
	Font headingFont;
	Font scoreFont;
	Font tutorialFont;
	Text scoreText;
	Text headingText;
	Text tutorialText;

// Music for the game
	Music bgMusic;
	Hero alex;

	float currentTime;
	float prevTime = 0.0f;

	int score = 0;
	bool gameOver = false;
	vector<Enemy*> enemies;
	vector<Rocket*> rockets;
	

// Functions
	bool checkCollision(Sprite sprite1, Sprite sprite2);
	void shoot();
	void spawnEnemy();
	void reset();
	void init();
	void updateInput();
	void update(float dt);
	void draw();
};

