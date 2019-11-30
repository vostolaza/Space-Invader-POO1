#include "CGame.h"

CGame::CGame(sf::RenderWindow *_palCanvas):palCanvas(_palCanvas) {
    // Generar el texto con el puntaje
    pScore = new Score(palCanvas);

    // Generar la nave a ser controlada por el usuario
    pTurret = new Turret(palCanvas, palCanvas-> getSize().x / 2.0f - 128, palCanvas->getSize().y - 100.0f, 4);

    //Generar las hordas de aliens
    for (int i = 0; i < nAliens; i++) {
        pAlien = new Octopus(palCanvas, 30.0f + (float)i * 180, 10, 0.2, 0.2);
        vAlien.push_back(pAlien);
    }
    for (int i = 0; i < nAliens; i++){
        pAlien = new Crab(palCanvas, 20.0f + (float)i * 180, 120, 0.2, 0.2);
        vAlien.push_back(pAlien);
    }
    for (int i = 0; i < nAliens-1; i++) {
        pAlien = new Octopus(palCanvas, 80.0f + (float)i * 180, 230, 0.2, 0.2);
        vAlien.push_back(pAlien);
    }
    for (int i = 0; i < nAliens-1; i++){
        pAlien = new Crab(palCanvas, 74.0f + (float)i * 180, 340, 0.2, 0.2);
        vAlien.push_back(pAlien);
    }

}

CGame::~CGame() {
    delete pTurret;
    for (auto &alien: vAlien)
        delete alien;
    for (auto &bala: vBala)
        delete bala;
    for (auto &bala: vBalaEnemiga)
        delete bala;
}

void CGame::run()
{
//    music.play();
    while (palCanvas->isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void CGame::render()
{
    palCanvas->clear();
    dibujaBorde(palCanvas);
    if(!game_over) {
        if (!boss_fight)
            for (auto &i: vAlien)
                i->Muestrate();
        else
            pBoss -> Muestrate();
        pTurret->Muestrate();
        for (auto &i : vBala) {
            i->Muestrate();
        }
        for (auto &i : vBalaEnemiga) {
            i->Muestrate();
        }
    }
    else
        gameOver();
    pScore ->Muestrate();
    palCanvas->display();
}

void CGame::processEvents()
{
    sf::Event event{};
    while (palCanvas->pollEvent(event))
    {
        switch (event.type)
        {case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                palCanvas->close();
                break;
            default:
                break;
        }
    }
}

void CGame::handlePlayerInput(sf::Keyboard::Key key,
                              bool isPressed)
{
    // Registrar los movimientos del jugador
    if (key == sf::Keyboard::Left)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::Right)
        mIsMovingRight = isPressed;

    // Registrar los disparos con un pequeño delay para que no se pueda disparar continuamente
    if (key == Keyboard::Space || key == Keyboard::Up) {
        if (clock.getElapsedTime().asSeconds() > 0.1f) {
            mIsShooting = isPressed;
            clock.restart();
        } else mIsShooting = false;
    }
}

void CGame::update()
{
    if(!game_over) {
        // Movimiento de la nave/usuario
        sf::Vector2f movement(0.f, 0.f);
        if (pTurret->getPosX() >= 10)
            if (mIsMovingLeft)
                movement.x -= 1.f * pTurret->getVelX();
        if (pTurret->getPosX() <= palCanvas->getSize().x - 138.0f)
            if (mIsMovingRight)
                movement.x += 1.f * pTurret->getVelX();
        pTurret->mover(movement);

        // Movimiento de los alien
        if(!boss_fight) {
            for (auto i: vAlien) {
                if (i->getPosX() <= 10 || i->getPosX() + i->getWidth() >= palCanvas->getSize().x - 10.0f)
                    for (auto &j: vAlien) {
                        j->nextRound();
                        if (j->getPosY() + j->getHeight() >= palCanvas->getSize().y) {
                            game_over = true;
                        }
                    }
                i->Muevete();
                if (i->Dispara()) {
                    Bala *pBala = new Bala(palCanvas, i, -5);
                    vBalaEnemiga.push_back(pBala);
                }
            }
        } else{
            pBoss -> Muevete();
            if (pBoss->getPosX() <= 10 || pBoss->getPosX() + pBoss->getWidth() >= palCanvas->getSize().x - 10.0f)
                pBoss -> reverseX();
            if (pBoss ->Dispara()){
                Bala *pBala = new Bala(palCanvas, pBoss, -5);
                vBalaEnemiga.push_back(pBala);
            }
        }
        // Registrar disparos
        if (mIsShooting) {
            Bala *pBala = new Bala(palCanvas, pTurret, 5);
            vBala.push_back(pBala);
            mIsShooting = false;
        }
        for (auto &i : vBala) {
            i->Muevete();
        }
        for (auto &i : vBalaEnemiga)
            i->Muevete();

        // Chequear si la bala conecto
        if (!boss_fight){
            registerHit(vBala, vAlien, pScore, boss_fight);
            if (vBala.empty()){
                pBoss = new UFO(palCanvas, palCanvas->getSize().x/2.0f -250, 350.0f, 0.8, 0);
            }
        } else
            registerBossHit(vBala, pBoss, pScore, game_over, result);

        if (registerEnemyHit(palCanvas, pTurret, vBalaEnemiga)){
            pTurret -> gotHit();
            if (pTurret -> getLives() <= 0)
                game_over = true;
            }
    }
}

void CGame::gameOver() {
    Font font;
    font.loadFromFile("../Arcade.TTF");
    Text text;
    text.setFont(font);
    text.setCharacterSize(200);

    if (result == 0){
        text.setString("GAME OVER");
    text.setPosition(100, palCanvas->getSize().y / 2.0f - 200);
    }
    else{
        text.setString("YOU WIN");
        text.setPosition(275, palCanvas -> getSize().y/2.0f - 200);}

    palCanvas -> draw(text);
}
