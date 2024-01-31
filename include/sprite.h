#pragma once
#include "SFML/Graphics.hpp"

class Sprite {
private:
    int width;
    int height;
    float scale_x;
    float scale_y;
    int frame;

    float x;
    float y;

    sf::Texture texture;

public:
    sf::Sprite sprite;

    Sprite(std::string texture_file);

    sf::Vector2u getTextureSize();

    void setWidth(int a);
    void setHeight(int a);
    void setScale(float a, float b);

    int getX();
    void setX(float a);
    int getY();
    void setY(float a);
    void addY(float a);
    void setPos(float a, float b);
    void updatePos();
    
    int getFrame();
    void setFrame(int a);
    void setImg();
};