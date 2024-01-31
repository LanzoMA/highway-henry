#pragma once
#include <string>

class Game
{
private:
    bool playing = false;
    bool game_over = false;
    bool debugging = false;

    const float INIT_VEL = 1.0f;
    const float ACCELERATION = 0.01f;

    int score = 0;
    float vel = INIT_VEL;
    
    const std::string GAME_OVER_TEXT = "Car collided with portal.\n";

public:
    void update();

    bool isPlaying();
    void setPlaying(bool a);

    bool isGameOver();
    void setGameOver(bool a);

    void gameOver();

    bool getDebugStatus();
    void toggleDebugeMode();

    int getScore();
    void resetScore();
    void incrementScore();

    float getVel();
    void accelerate();

    float getAcceleration();
};