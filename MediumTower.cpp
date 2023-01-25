#include "MediumTower.hpp"

MediumTower::MediumTower()
{
    loadFromFile("art/Tower/Medium Tower.png");
}

void MediumTower::setScale(float windowHeight)
{
    float scale = windowHeight/sprite.getLocalBounds().height/2.5;
    sprite.setScale(scale,scale);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
}

void MediumTower::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos-sprite.getOrigin());
}
