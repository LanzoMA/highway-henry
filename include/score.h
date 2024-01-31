#pragma once
#include "text.h"

class Score : public Text
{
public:
	Score(std::string info, int size);

	void setScore(int score);
	void resetScore();
};