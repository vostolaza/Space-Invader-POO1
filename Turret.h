#ifndef PROYECTO_TURRET_H
#define PROYECTO_TURRET_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Turret {
    RenderWindow *palCanvas;
    float posX;
    float posY;
    float velX;
    Texture texture;
    Sprite sprite;
    Font font;
    Text text;
    int Lives = 3;

public:
    Turret(RenderWindow *_palCanvas, float _posX, float _posY, float _velX):
            palCanvas(_palCanvas), posX(_posX), posY(_posY), velX(_velX){}
    virtual  ~Turret()= default;
    float getPosY(){return posY;}
    float getPosX(){return posX;}
    float getVelX(){return velX;}
    int getLives(){return Lives;}
    void gotHit(){Lives--;};
    void Muestrate();
    void mover(Vector2f m);
};

#endif //PROYECTO_TURRET_H
