#pragma once
#include <../include/SFML/Graphics.hpp>
#include <../include/SFML/Audio.hpp>
#include <vector>
#include <map>
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

// Paths through the folders to the files
	std::vector<std::string> spritePaths;

// Where the background and sky will be positioned
	std::vector<std::string> spritePositions;

// Initialize init class
	Init initialization;

// Draw on screen the gameplay
	void draw();

// Variables to make the window
	sf::RenderWindow window;
	sf::VideoMode vm;

// Variables to load images
	std::map<std::string, sf::Texture*> textures;
	vector<sf::Sprite> sprites;
	vector<sf::Vector2f> scales;

// Variables for text
	sf::Font font;
	vector<sf::Text> texts;

// Variables for vfx
	sf::Music music;
	sf::SoundBuffer soundBuff;
	vector<sf::Sound> sounds;
};

