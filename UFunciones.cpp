#include "UFunciones.h"

using namespace sf;
void dibujaBorde(RenderWindow *palCanvas) {
    RectangleShape bordeIzquierdo(sf::Vector2f(10, palCanvas->getSize().y));
    bordeIzquierdo.setPosition(0, 0);
    bordeIzquierdo.setFillColor(Color::White);
    palCanvas->draw(bordeIzquierdo);

    RectangleShape bordeDerecho(sf::Vector2f(10, palCanvas->getSize().y));
    bordeDerecho.setPosition(palCanvas->getSize().x-10.0f, 0);
    bordeDerecho.setFillColor(Color::White);
    palCanvas->draw(bordeDerecho);

    RectangleShape bordeSuperior(sf::Vector2f(palCanvas->getSize().x, 10));
    bordeSuperior.setPosition(0, 0);
    bordeSuperior.setFillColor(Color::White);
    palCanvas->draw(bordeSuperior);

    RectangleShape bordeInferior(sf::Vector2f(palCanvas->getSize().x, 10));
    bordeInferior.setPosition(0, palCanvas->getSize().y-10.0f);
    bordeInferior.setFillColor(Color::White);
    palCanvas->draw(bordeInferior);
}

void registerHit(vector<Bala*> &vBala, vector<Alien*> &vAlien, Score *&pScore, bool &boss_fight){
    int i = 0;
    for (auto &bala: vBala){
        if (bala->getPosY() < 0) {
            delete bala;
            vBala.erase(vBala.begin() + i);
        }
        int j = 0;
        for (auto &alien: vAlien){
            if (bala->getPosX()>= alien->getPosX()&& bala->getPosX()+10 <= alien ->getPosX()+ alien->getWidth()){
                if(bala->getPosY()<= alien->getPosY() + alien->getHeight() && bala->getPosY()+20 >= alien ->getPosY()){
                    delete bala;
                    vBala.erase(vBala.begin()+i);
                    pScore ->increaseScore(alien);
                    delete alien;
                    vAlien.erase(vAlien.begin() + j);
                    if (vAlien.empty()) {
                        boss_fight = true;
                    }
                }
            }
            j++;
        }
        i ++;
    }
}

void registerBossHit(vector<Bala*> &vBala, UFO *&pBoss, Score *&pScore, bool &game_over, int &result){
    int i = 0;
    for (auto &bala: vBala){
        if (bala->getPosY() < 0) {
            delete bala;
            vBala.erase(vBala.begin() + i);
        }

            if (bala->getPosX()>= pBoss->getPosX()&& bala->getPosX()+10 <= pBoss ->getPosX()+ pBoss->getWidth()){
                if(bala->getPosY()<= pBoss->getPosY() + pBoss->getHeight() && bala->getPosY()+20 >= pBoss ->getPosY()){
                    delete bala;
                    vBala.erase(vBala.begin()+i);
                    pScore ->increaseScore(pBoss);
                    pBoss -> gotHit();
                    if (pBoss -> getLives() <= 0) {
                        result = 1;
                        game_over = true;
                    }
                    }

        }
        i ++;
    }
}


bool registerEnemyHit(RenderWindow *palCanvas, Turret *&pTurret, vector<Bala*> &vBalaEnemiga){
    int i = 0;
    for (auto &bala: vBalaEnemiga){
        if (bala -> getPosY() + 20 >= palCanvas->getSize().y - 10.0f){
            delete bala;
            vBalaEnemiga.erase(vBalaEnemiga.begin() + i);
        }
        if (bala -> getPosY() + 20 >= pTurret -> getPosY() && bala -> getPosX() >= pTurret -> getPosX()
        && bala -> getPosX() + 10 <= pTurret -> getPosX() + 128){
            delete bala;
            vBalaEnemiga.erase(vBalaEnemiga.begin()+i);
            return true;
        }
    i++;
    }
    return false;
}
