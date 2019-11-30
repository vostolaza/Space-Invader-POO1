#ifndef PROYECTO_BALA_H
#define PROYECTO_BALA_H
#include <SFML/Graphics.hpp>
#include "Turret.h"
#include "Alien.h"

using namespace sf;

class Bala {
    RenderWindow *palCanvas;
    Turret *pTurret = nullptr;
    Alien *pAlien = nullptr;
    float posX;
    float posY;
    float velY;
public:
    Bala(RenderWindow *_palCanvas, Turret *_pTurret, float _velY);
    Bala(RenderWindow *_palCanvas, Alien *_pAlien, float _velY);
    float getPosX(){return posX;}
    float getPosY(){return posY;}
    void Muevete(){posY -= velY;}
    void Muestrate();

};


#endif //PROYECTO_BALA_H
