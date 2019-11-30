#include "Turret.h"
void Turret::Muestrate() {
    texture.loadFromFile("../Laser Turret.png");
    sprite.setTexture(texture);
    sprite.setPosition(posX, posY);
    palCanvas -> draw(sprite);

    font.loadFromFile("../Arcade.TTF");
    text.setFont(font);
    text.setString("Lives: " + std::to_string(Lives));
    text.setCharacterSize(40);
    text.setFillColor(::Color::Green);
    text.setPosition(30, 30);
    palCanvas -> draw(text);
}

void Turret::mover(Vector2f m) {
    posX += m.x;
    posY += m.y;
}

