#include "sprite.h"
#include <iostream>

Sprite::Sprite(std::string texture_file) {
    if (!texture.loadFromFile(texture_file))
        std::cout << "ERROR: Unable to load " << texture_file << "." << std::endl;

    sprite.setTexture(texture);

    x = y = frame = 0;
}

sf::Vector2u Sprite::getTextureSize() {
    return texture.getSize();
}

void Sprite::setWidth(int a) { width = a; }
void Sprite::setHeight(int a) { height = a; }

int Sprite::getX() {
    return x;
}

void Sprite::setX(float a) {
    x = a;
    sprite.setPosition(x, y);
}

int Sprite::getY() {
    return y;
}

void Sprite::setY(float a) {
    y = a;
    sprite.setPosition(x, y);
}

void Sprite::addY(float a) {
    y += a;
}


void Sprite::setPos(float a, float b) {
    x = a;
    y = b;
    sprite.setPosition(x, y);
}

void Sprite::updatePos() {
    sprite.setPosition(x, y);
}

void Sprite::setScale(float a, float b) {
    scale_x = a;
    scale_y = b;
    sprite.setScale(scale_x, scale_y);
}

int Sprite::getFrame() {
    return frame;
}

void Sprite::setFrame(int a) {
    frame = a;
}

void Sprite::setImg() {
    sprite.setTextureRect(sf::IntRect(frame, 0, width, height));
}
