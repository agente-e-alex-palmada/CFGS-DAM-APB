#include "../includeEn/Init.h"

Init::Init() {}

Init::~Init() {}

bool Init::sprite(std::map<std::string, sf::Texture*> textures, const std::vector<sf::Vector2f>& scales, std::vector<sf::Sprite>& sprites) {
    
    // Clear the vector to ensure no leftover sprites from previous calls
    sprites.clear();

    // Iterate through each texture and scale, creating a sprite for each one
    auto textureIt = textures.begin();
    auto scaleIt = scales.begin();

    while (textureIt != textures.end() && scaleIt != scales.end()) {
        sf::Sprite sprite(*textureIt->second);
        sprite.setScale(*scaleIt);
        sprites.push_back(sprite);

        ++textureIt;
        ++scaleIt;
    }

    return true;
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