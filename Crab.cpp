#include "Crab.h"

void Crab::Muestrate() {
    texture.loadFromFile("../Crab.png");
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
    palCanvas -> draw(sprite);
}

bool Crab::Dispara() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 10000);
    return dist(mt) == 1;
}
