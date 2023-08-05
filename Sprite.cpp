#include "Sprite.hpp"
#include <iostream>

Sprite::Sprite()
{

}

Sprite::Sprite(std::string path)
{
    setTexture(path);
}



sf::Sprite &Sprite::getSprite()
{
    return sprite;
}

void Sprite::setTexture(std::string path)
{
    if(!Texture.loadFromFile(path))
    {
        std::cout << "error failed load Texture" << std::endl;
    }
    sprite.setTexture(Texture);
}
