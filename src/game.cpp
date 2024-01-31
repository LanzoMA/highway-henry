#include "game.h"
#include <iostream>

void Game::update() {
    if (getDebugStatus()) {
        std::cout << vel << "\n";
    }
}

bool Game::isPlaying() {
    return playing;
}
void Game::setPlaying(bool a)
{
    playing = a;
}

bool Game::isGameOver()
{
    return game_over;
}


bool Game::getDebugStatus() {
    return debugging;
}

void Game::toggleDebugeMode() {
    debugging = (debugging) ? false : true;
}

int Game::getScore() {
    return score;
}

void Game::resetScore() {
    score = 0;
}

void Game::incrementScore() {
    score += 1;
}

float Game::getVel() {
    return vel;
}

void Game::accelerate() {
    vel += ACCELERATION;
}

float Game::getAcceleration() {
    return ACCELERATION;
}

void Game::setGameOver(bool a) {
    game_over = a;
}

void Game::gameOver() {
    playing = false;
    game_over = true;

    resetScore();
    vel = INIT_VEL;
}