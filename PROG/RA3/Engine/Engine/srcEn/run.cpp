#include "../includeEn/Engine.h"

int Engine::run() {
    window.create(vm.getDesktopMode(), "Hero Game", sf::Style::Default);
    initialization.sprite(spritePaths, sprites);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();

        }

        window.clear();
        window.display();
    }
    return 0;
}