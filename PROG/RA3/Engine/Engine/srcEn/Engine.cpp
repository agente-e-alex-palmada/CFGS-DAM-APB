#include "../includeEn/Engine.h"

Engine::Engine() {
    // A more efficient approach: creating textures in a more structured way
    std::vector<std::pair<std::string, std::string>> textureFiles = {
        {"background", "assets/graphics/bg.jpg"},
        {"hero", "assets/graphics/hero.png"},
        {"bullet", "assets/graphics/bullet.png"},
        {"enemy", "assets/graphics/enemy1.png"}
    };

    std::vector<sf::Vector2f> textureScales = {
        {1.4f, 1.4f}, // Background scale
        {0.5f, 0.5f}, // Bullet scale
        {0.5f, 0.5f}, // Enemy scale
        {0.6f, 0.6f}  // Hero scale
    };

    // Loop through the textures and load them, assign the scale, and store them
    for (int i = 0; i < textureFiles.size(); ++i) {
        sf::Texture* texture = new sf::Texture(); // Create a new texture
        if (texture->loadFromFile(textureFiles[i].second)) {
            textures[textureFiles[i].first] = texture; // Add texture to map
            scales.push_back(textureScales[i]);        // Add the scale to scales vector
        }
        else {
            std::cerr << "Error loading texture: " << textureFiles[i].second << std::endl;
        }
    }
}

Engine::~Engine() {}