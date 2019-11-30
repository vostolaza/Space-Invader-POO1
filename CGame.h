#ifndef PROYECTO_CGAME_H
#define PROYECTO_CGAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include <SFML/Audio/Music.hpp>
#include "Turret.h"
#include "Crab.h"
#include "Octopus.h"
#include "UFO.h"
#include "Bala.h"
#include "UFunciones.h"
#include "Score.h"
#include "UFO.h"


class CGame {
private:
    sf::RenderWindow *palCanvas= nullptr;
    Turret *pTurret= nullptr;
    Alien *pAlien = nullptr;
    UFO *pBoss = nullptr;
    Clock clock;
    int nAliens = 10;
    Music music;
    Score *pScore;
    vector<Alien*> vAlien;
    vector<Bala*>  vBala;
    vector<Bala*> vBalaEnemiga;
    bool mIsMovingLeft=false;
    bool mIsMovingRight=false;
    bool mIsShooting = false;
    bool game_over = false;
    bool boss_fight = false;
    int result=0;
private:
    void   processEvents();
    void   update();
    void   render();
    void   handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
public:
    CGame(){}
    CGame(sf::RenderWindow *_palCanvas);
    virtual ~CGame();
    void   run();
    void gameOver();
    friend void registerHit(vector<Bala*> &vBala, vector<Alien*> &vAlien, Score *&pScore, bool &boss_fight);
    friend void dibujaBorde(RenderWindow *palCanvas);
    friend bool registerEnemyHit(RenderWindow *palCanvas, Turret *&pTurret, vector<Bala*> &vBalaEnemiga);

};



#endif //PROYECTO_CGAME_H
