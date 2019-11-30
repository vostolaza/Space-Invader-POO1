#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "CGame.h"
using namespace sf;

int main() {

    RenderWindow window(VideoMode(1920, 1920), "Space Invaders");
    CGame game(&window);
    game.run();

    return EXIT_SUCCESS;
}