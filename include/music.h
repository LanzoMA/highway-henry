#pragma once

class Music
{
public:
	Music(const char* filename);

	void set(int index);

private:
	const float MUSIC_VOL = 25.0f;
};