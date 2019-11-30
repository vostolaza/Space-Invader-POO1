#ifndef PROYECTO_OCTOPUS_H
#define PROYECTO_OCTOPUS_H


#include "Alien.h"

class Octopus: public Alien {
public:
    Octopus(RenderWindow *_palCanvas, float _posX, float _posY, float _velX, float _velY):
                                    Alien(_palCanvas, _posX, _posY, _velX, _velY){ alienWidth = 95.0f;
                                                                                   alienHeight = 95.0f;
                                                                                    value = 20;}

    void Muestrate() override;
    bool Dispara() override;
};

#endif //PROYECTO_OCTOPUS_H
