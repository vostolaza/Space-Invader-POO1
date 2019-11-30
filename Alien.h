#ifndef PROYECTO_ALIEN_H
#define PROYECTO_ALIEN_H

#include <SFML/Graphics.hpp>
#include <string>
#include <random>

using namespace std;
using namespace sf;

class Alien {
protected:
    RenderWindow *palCanvas;
    float posX;
    float posY;
    float velX;
    float velY;
    Texture texture;
    Sprite sprite;
    float alienWidth{};
    float alienHeight{};
    int value;

public:
    Alien()= default;

    Alien(RenderWindow *_palCanvas, float _posX, float _posY, float _velX, float _velY):
                                                                    palCanvas(_palCanvas), posX(_posX), posY(_posY),
                                                                    velX(_velX), velY(_velY){}
    virtual ~Alien()= default;
    virtual void Muestrate()=0;
    virtual bool Dispara()=0;
    void Muevete();
    float getPosY(){return posY;}
    float getPosX(){return posX;}
    float getWidth(){return alienWidth;}
    int getValue(){return value;}
    float getHeight(){return alienHeight;}
    void nextRound(){velX *= -1.2; posY += alienHeight;}

};


#endif //PROYECTO_ALIEN_H
