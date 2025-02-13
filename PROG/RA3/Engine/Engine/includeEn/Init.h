#pragma once
#include <../include/SFML/Graphics.hpp>
#include <../include/SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>

class Init
{
public:
	Init();
	~Init();
	void sprite(std::vector<std::string>& path, std::vector<sf::Sprite>& sprites);
	//void afont(const string& path);
	//void atext(/*Here should go variables to create text??*/);
	//void amusic(const string& path);
	//void asound(const string& path);
};

