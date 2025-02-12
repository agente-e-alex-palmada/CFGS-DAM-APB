#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Engine.h"

using namespace sf;

Engine::Engine() {
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "Hero game - enemy", Style::Default);
}

Engine::~Engine() {

}

void Engine::init() {

// Load textures and set them
	skyTexture.loadFromFile("Assets/graphics/sky.png");
	skySprite.setTexture(skyTexture);
	bgTexture.loadFromFile("Assets/graphics/bg.png");
	bgSprite.setTexture(bgTexture);
	headingFont.loadFromFile("Assets/fonts/SnackerComic.ttf");
	scoreFont.loadFromFile("Assets/fonts/arial.ttf");

// Set fonts
	// Heading text	
	headingText.setFont(headingFont);
	headingText.setString("Tiny Bazooka");
	headingText.setCharacterSize(84);
	headingText.setFillColor(Color::Green);
	FloatRect headingbounds = headingText.getLocalBounds();
	headingText.setOrigin(headingbounds.width / 2, headingbounds.height / 2);
	headingText.setPosition(Vector2f(viewSize.x * 0.5f, viewSize.y * 0.10f));
	
	// Score text
	scoreText.setFont(scoreFont);
	scoreText.setString("Score: "+score);
	scoreText.setCharacterSize(75);
	scoreText.setFillColor(Color::White);
	
	// Tutorial text
	tutorialText.setString("Press 'Z' to Fire and Start Game, 'Space' to Jump");
	tutorialText.setCharacterSize(35);
	tutorialText.setFillColor(Color::Red);
	FloatRect tutorialbounds = tutorialText.getLocalBounds();
	tutorialText.setOrigin(tutorialbounds.width / 2, tutorialbounds.height / 2);
	tutorialText.setPosition(Vector2f(viewSize.x * 0.5f, viewSize.y * 0.20f));
	
// Audio
	bgMusic.openFromFile("Assets/audio/bgMusic.ogg");
	bgMusic.play();
	
// Character
	alex.init("Assets/graphics/hero.png", Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 200);
	srand((int)time(0));
}

int Engine::run() {
	Clock clock;
	init();
	while (window.isOpen()) {
		updateInput();
		Time dt = clock.restart();
		if (gameOver) {
			update(dt.asSeconds());
		}
		draw();
	}
	return 0;
}

void Engine::updateInput() {
	Event event;
	while (window.pollEvent(event)) {
		if (event.key.code == Keyboard::Space)
		{
			alex.jump(750.0f);
		}
		if (event.key.code == Keyboard::Z)
		{
			if (!gameOver)
			{
				gameOver = true;
				reset();
			}
			else
			{
				shoot();
			}
		}
	}
	if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) {
		window.close();
	}
}

void Engine::update(float dt) {
	alex.update(dt);
	currentTime += dt;
	if (currentTime >= prevTime + 1.125f)
	{
		spawnEnemy(); 
		prevTime = currentTime;
	}
	for (int i = 0; i < enemies.size(); i++)
	{
		Enemy *enemy = enemies[i];
		enemy->update(dt);
		if (enemy->getSprite().getPosition().x < 0)
		{
			enemies.erase(enemies.begin() + i);
			delete(enemy);
		}
	}
}

void Engine::draw() {
	window.clear(Color::Red);
	window.draw(bgSprite);
	window.draw(skySprite);
	window.draw(alex.getSprite());
	if (!gameOver) {
		window.draw(headingText);
		window.draw(tutorialText);
	}
	else {
		window.draw(scoreText);
	}
	for (Enemy* enemy : enemies) {
		window.draw(enemy->getSprite());
	}
	window.display();
}


bool Engine::checkCollision(Sprite sprite1, Sprite sprite2)
{
	FloatRect shape1 = sprite1.getGlobalBounds();
	FloatRect shape2 = sprite2.getGlobalBounds();
	if (shape1.intersects(shape2)) {
		return true;
	}
	else {
		return false;
	}
}

void Engine::shoot()
{
	Rocket* rocket = new Rocket();
	rocket->init("Assets/graphics/rocket.png", alex.getSprite().getPosition(), 200);
	rockets.push_back(rocket);
}

void Engine::spawnEnemy()
{
	int randLoc = rand() % 3;
	Vector2f enemyPos;
	float speed;
	switch (randLoc) {
	case 0: enemyPos = Vector2f(viewSize.x, viewSize.y * 0.75f);
		speed = -400; break;
	case 1: enemyPos = Vector2f(viewSize.x, viewSize.y * 0.60f);
		speed = -550; break;
	case 2: enemyPos = Vector2f(viewSize.x, viewSize.y * 0.40f);
		speed = -650; break;
	default: printf("incorrect y value \n"); break;
		Enemy* enemy = new Enemy();
		enemy->init("Assets/graphics/enemy.png", enemyPos, speed);
		enemies.push_back(enemy);
	}
}
void Engine::reset() {
	score = 0;
	currentTime = 0.0f;
	prevTime = 0.0;
	for (Enemy* enemy : enemies) {
		delete(enemy);
	}
	for (Rocket* rocket : rockets) {
		delete(rocket);
	}
	enemies.clear();
	rockets.clear();
}