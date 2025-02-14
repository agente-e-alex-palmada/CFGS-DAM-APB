#include "../includeEn/Engine.h"

int Engine::run() {
    window.create(vm.getDesktopMode(), "Hero Game", sf::Style::Fullscreen);
    
    // Depuration couts and loading sprites and positions for sprites
    if (initialization.sprite(textures, scales, sprites))
    {
        cout << "Sprites have been loaded\n";
    }
    while (window.isOpen())
    {
        sf::Event event;
        // Loop that mantains the game running
        while (window.pollEvent(event))
        {
            // Closes the game when escape is pressed
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }
        draw();
    }
    return 0;
}