#include "text.h"
#include <iostream>

Text::Text(std::string info, int size, int x, int y)
{
    if (!jb_font.loadFromFile("../fonts/JetBrainsMono-Regular.ttf"))
        std::cout << "ERROR: Unable to load font!" << std::endl;

    display.setFont(jb_font);
    display.setString(info);
    display.setCharacterSize(size);
    display.setFillColor(sf::Color::White);
    display.setPosition(x, y);

}

