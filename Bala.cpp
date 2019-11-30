#include "Bala.h"

void Bala::Muestrate() {
    RectangleShape rectangle(sf::Vector2f(10,20));
    rectangle.setPosition(posX,posY);
    rectangle.setFillColor(Color::White);
    palCanvas->draw(rectangle);
}

// Balas usuario
Bala::Bala(RenderWindow *_palCanvas, Turret *_pTurret, float _velY):palCanvas(_palCanvas),pTurret(_pTurret), velY(_velY)
{
    posX = pTurret->getPosX()+64;
    posY = palCanvas->getSize().y-150.0f;
}

// Balas Enemigas
Bala::Bala(RenderWindow *_palCanvas, Alien *_pAlien, float _velY):palCanvas(_palCanvas), pAlien(_pAlien), velY(_velY)
{
    posX = pAlien -> getPosX() + pAlien -> getWidth()/2;
    posY = pAlien ->getPosY() + pAlien -> getHeight();
}


