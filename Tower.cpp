#include "Tower.hpp"

Tower::Tower()
{

}

sf::Sprite & Tower::getSprite()
{
    return sprite;
}

void Tower::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos-sprite.getOrigin());
}

void Tower::setScale(float windowHeight)
{
    float scale = windowHeight/sprite.getLocalBounds().height/3;
    sprite.setScale(scale,scale);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);

}

void Tower::loadFromFile(std::string path)
{
    if(!texture.loadFromFile(path))
    {
        std::cout << "error" <<std::endl;
    }
    sprite.setTexture(texture);

}



