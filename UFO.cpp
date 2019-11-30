#include "UFO.h"

void UFO::Muestrate() {
    texture.loadFromFile("../UFO.png");
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
    palCanvas -> draw(sprite);

    font.loadFromFile("../Arcade.TTF");
    text.setFont(font);
    text.setString("Boss Lives: " + std::to_string(Lives));
    text.setCharacterSize(40);
    text.setFillColor(::Color::Green);
    text.setPosition(palCanvas -> getSize().x/2.0f -250.0f, 30);
    palCanvas -> draw(text);
}

bool UFO::Dispara() {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, 1000);
    return dist(mt) <= 5;
}