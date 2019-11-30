#ifndef PROYECTO_CRAB_H
#define PROYECTO_CRAB_H

#include "Alien.h"

class Crab: public Alien {
public:
    Crab(RenderWindow *_palCanvas, float _posX, float _posY, float _velX, float _velY):
                                                        Alien(_palCanvas, _posX, _posY, _velX, _velY){
                                                        alienWidth = 128.0f; alienHeight = 95.0f;
                                                        value = 10;}
    void Muestrate() override;
    bool Dispara() override;
};

#endif //PROYECTO_CRAB_H
