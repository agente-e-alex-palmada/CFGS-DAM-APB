//Including libraries
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

//Standart declaration
using namespace sf;
using namespace std;

//Declaring gobal variables
const int XMAX = 1920, YMAX = 1080, BLOCK_SPRITES = 5, BLOCKS = 48, BACKGROUNDS = 3, ARROWS = 2;

void breakBlock() {

}

void ballMovement() {

}

//The movement for the bar
void barMovement() {

}

//Drawing what's on scene
void draw(RenderWindow &window) {
	
	
	window.display();
}

//Initialization
void init(Texture& blockTexture, Texture& ballTexture, Texture& barTexture, Texture backgroundTexture[], Texture arrowTexture[], Sprite block[], Sprite& ball, Sprite& bar, Sprite backgrounds[], Sprite& arrow) {
	for (int i = 0; i < BLOCK_SPRITES; i++)
	{
		string blockPath = "./assets/graphics/sprites/block" + to_string(i) + ".png";
		blockTexture.loadFromFile(blockPath);
	}
	ballTexture.loadFromFile("./assets/graphics/sprites/ball.png");
	barTexture.loadFromFile("./assets/graphics/sprites/bar.png");
	for (int i = 0; i < BACKGROUNDS; i++) {
		string backgroundPath = "./assets/graphics/backgrounds/background" + to_string(i) + ".png";
		backgroundTexture[i].loadFromFile(backgroundPath);
		backgrounds[i].setTexture(backgroundTexture[i]);
	}
	for (int i = 0; i < ARROWS; i++)
	{
		string arrowPath = "./assets/graphics/icons/arrow" + to_string(i) + ".png";
		arrowTexture[i].loadFromFile(arrowPath);
		arrow.setTexture(arrowTexture[i]);
	}
	for (int i = 0; i < BLOCKS; i++)
	{
		block[i].setTexture(blockTexture);
	}
	ball.setTexture(ballTexture);
	bar.setTexture(barTexture);
}

int main(){
	int score;
	float barSpeed, bar_speed;
	VideoMode vm(XMAX, YMAX);
	RenderWindow window(vm, "Fronto game", Style::Titlebar);
	Texture blockTexture, ballTexture, barTexture, backgroundTexture[BACKGROUNDS], arrowTexture[ARROWS];
	Sprite block[BLOCKS], ball, bar, arrow, backgrounds[BACKGROUNDS];
	Event event;
	init(blockTexture, ballTexture, barTexture, backgroundTexture, arrowTexture, block, ball, bar, backgrounds, arrow);
	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
				window.close();
		}
		barMovement();
		draw(window);
	}
	return 0;
}