#include "Octopus.h"

void Octopus::Muestrate() {
    texture.loadFromFile("../Octopus.png");
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
    palCanvas -> draw(sprite);
}

bool Octopus::Dispara() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 8000);
    return dist(mt) <= 5;
}

