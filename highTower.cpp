#include "highTower.hpp"

void HighTower::setScale(float windowHeight)
{
    float scale = windowHeight/sprite.getLocalBounds().height/2.5;
    sprite.setScale(scale,scale);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
}

void HighTower::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos-sprite.getOrigin());
}
