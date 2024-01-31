#include "music.h"
#include <SFML/Audio.hpp>
#include <iostream>

Music::Music(const char* filename)
{
	sf::Music music;

	if (!music.openFromFile(filename)) {
		std::cout << "ERROR: Unable to load " << filename << ".\n";
	}

}