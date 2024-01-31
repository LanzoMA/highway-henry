#pragma once
#include "SFML/Graphics.hpp"
#include <string>

class Text
{
public:
    sf::Text display;
    sf::Font jb_font;

    Text(std::string info, int size, int x, int y);

 
};