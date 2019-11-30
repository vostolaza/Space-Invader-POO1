#ifndef PROYECTO_SCORE_H
#define PROYECTO_SCORE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Alien.h"
using namespace sf;
using namespace std;

class Score {
    RenderWindow *palCanvas;
    Font font;
    Text text;
    int nScore = 0;

public:
    Score(RenderWindow *_palCanvas):palCanvas(_palCanvas){};
    void Muestrate();
    void increaseScore(Alien *pAlien){nScore+= pAlien -> getValue();}
};


#endif //PROYECTO_SCORE_H
