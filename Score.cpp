#include "Score.h"

void Score::Muestrate() {
    font.loadFromFile("../Arcade.TTF");
    text.setFont(font);
    text.setString("Score: " + to_string(nScore));
    text.setCharacterSize(40);
    text.setFillColor(::Color::Green);
    text.setPosition(palCanvas -> getSize().x - 400.0f, 30);
    palCanvas -> draw(text);

}
