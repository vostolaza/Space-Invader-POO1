#ifndef PROYECTO_UFUNCIONES_H
#define PROYECTO_UFUNCIONES_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include "Alien.h"
#include "UFO.h"
#include "Bala.h"
#include "Score.h"
using namespace sf;

void dibujaBorde(RenderWindow *palCanvas);
void registerHit(vector<Bala*> &vBala, vector<Alien*> &vAlien, Score *&pScore, bool &boss_fight);
bool registerEnemyHit(RenderWindow *palCanvas, Turret *&pTurret, vector<Bala*> &vBalaEnemiga);
void registerBossHit(vector<Bala*> &vBala, UFO *&pBoss, Score *&pScore, bool &game_over, int &result);

#endif //PROYECTO_UFUNCIONES_H
