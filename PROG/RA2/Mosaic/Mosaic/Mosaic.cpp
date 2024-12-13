#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    //Here we create thw window size and the title
    Vector2f viewSize(1024, 700);
    VideoMode vm(viewSize.x, viewSize.y);
    RenderWindow window(vm, "Geometric Mosaic", Style::Default);
    //A loop that waits to the ESC key to be pressed to close the game
    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        //We create rectangle shapes to create the lines
        RectangleShape border1(Vector2f(1024, 20)), border2(Vector2f(20, 700)), border3(Vector2f(1024, 20)), border4(Vector2f(20, 700)), lineH1(Vector2f(1024, 20)), lineH2(Vector2f(1024, 20)), lineH3(Vector2f(500, 20)), lineV1(Vector2f(20, 700)), lineV2(Vector2f(20, 700)), lineV3(Vector2f(20, 700)), lineV4(Vector2f(20, 500));

        //We create the squares to fill the blank spaces
        RectangleShape square1(Vector2f(180, 180)), square2(Vector2f(380, 180)), square3(Vector2f(280, 280)), square4(Vector2f(280, 80));

        //These are all the lines with their color and position
        border1.setFillColor(Color::Black);
        border1.setPosition(0, 0);
        border2.setFillColor(Color::Black);
        border2.setPosition(0, 0);
        border3.setFillColor(Color::Black);
        border3.setPosition(0, 680);
        border4.setFillColor(Color::Black);
        border4.setPosition(1004, 0);
        lineH1.setFillColor(Color::Black);
        lineH1.setPosition(0, 200);
        lineH2.setFillColor(Color::Black);
        lineH2.setPosition(0, 500);
        lineH3.setFillColor(Color::Black);
        lineH3.setPosition(0, 400);
        lineV1.setFillColor(Color::Black);
        lineV1.setPosition(200, 0);
        lineV2.setFillColor(Color::Black);
        lineV2.setPosition(500, 0);
        lineV3.setFillColor(Color::Black);
        lineV3.setPosition(800, 0);
        lineV4.setFillColor(Color::Black);
        lineV4.setPosition(900, 0);
        
        //We create the colors and the possitions in the blank holes
        square1.setFillColor(Color::Red);
        square1.setPosition(20, 20);
        square2.setFillColor(Color::Yellow);
        square2.setPosition(520, 20);
        square3.setFillColor(Color::Red);
        square3.setPosition(520, 220);
        square4.setFillColor(Color::Blue);
        square4.setPosition(220, 420);

        //It draws all the objects we created
        window.clear(Color::White);
        window.draw(border1);
        window.draw(border2);
        window.draw(border3);
        window.draw(border4);
        window.draw(lineH1);
        window.draw(lineH2);
        window.draw(lineH3);
        window.draw(lineV1);
        window.draw(lineV2);
        window.draw(lineV3);
        window.draw(lineV4);
        window.draw(square1);
        window.draw(square2);
        window.draw(square3);
        window.draw(square4);
        window.display();
    }
    return 0;
}
