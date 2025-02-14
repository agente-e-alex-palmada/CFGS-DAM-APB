#include "../includeEn/Engine.h"

void Engine::draw() {
    // Clear the window at the start of the draw call
    window.clear();
    for (int i = 0; i < sprites.size(); i++)
    {
        // Draw each sprite
        window.draw(sprites[i]);
    }

    // Display the rendered frame
    window.display();
}
