#pragma once
#include <../include/SFML/Graphics.hpp>
#include <../include/SFML/Audio.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>

class Init
{
public:
	Init();
	~Init();
	bool sprite(std::map<std::string, sf::Texture*> textures, const std::vector<sf::Vector2f>& scales, std::vector<sf::Sprite>& sprites);
	//void afont(const string& path);
	//void atext(/*Here should go variables to create text??*/);
	//void amusic(const string& path);
	//void asound(const string& path);
};

