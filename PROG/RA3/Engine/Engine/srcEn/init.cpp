#include "../includeEn/Init.h"

Init::Init() {}

Init::~Init() {}

void Init::sprite(std::vector<std::string>& path, std::vector<sf::Sprite>& sprites) {
	sf::Texture texture;
	int numPath = path.size();
	for (int i = 0; i < numPath; i++)
	{
		if (!texture.loadFromFile(path[i])) {
			std::cout << "Can't load from file: " << path[i] << std::endl;
		} else {
			sf::Sprite sprite(texture);
			sprites.push_back(sprite);
		}
	}
}

//void Init::afont(const string& path) {
//
//}
//
//void Init::amusic(const string& path) {
//
//}
//
//void Init::asound(const string& path) {
//
//}