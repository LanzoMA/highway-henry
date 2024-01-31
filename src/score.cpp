#include "score.h"

Score::Score(std::string info, int size) : Text(info, size, 10, 10) {}

void Score::setScore(int score) {
    display.setString("Score: " + std::to_string(score));
}

void Score::resetScore() {
    display.setString("Score: 0");
}