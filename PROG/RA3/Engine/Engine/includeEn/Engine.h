#pragma once
#include <../include/SFML/Graphics.hpp>
#include <../include/SFML/Audio.hpp>
#include <vector>
#include <string>
#include "Init.h"


using namespace std;

class Engine
{
public:
// Default constructor and destructor
	Engine();
	~Engine();

// Function to run the game
	int run();

private:

	std::vector<std::string> spritePaths;

	Init initialization;


// Draw on screen the gameplay
	void draw();

// Variables to make the window
	sf::RenderWindow window;
	sf::VideoMode vm;

// Variables to load images
	sf::Texture texture;
	vector<sf::Sprite> sprites;

// Variables for text
	sf::Font font;
	vector<sf::Text> texts;

// Variables for vfx
	sf::Music music;
	sf::SoundBuffer soundBuff;
	vector<sf::Sound> sounds;
};

