#ifndef PROYECTO_UFO_H
#define PROYECTO_UFO_H


#include "Alien.h"

class UFO: public Alien {
    int Lives = 30;
    Text text;
    Font font;
public:
    UFO(RenderWindow *_palCanvas, float _posX, float _posY, float _velX, float _velY):
                            Alien(_palCanvas, _posX, _posY, _velX, _velY)
                            { alienWidth = 500.0f; alienHeight = 233.0f; value = 10;}
    void Muestrate() override;
    bool Dispara() override;
    int getLives(){return Lives;}
    void gotHit(){Lives--;}
    void reverseX(){velX *= -1;}
};


#endif //PROYECTO_UFO_H
