#include "MediumTower.hpp"

MediumTower::MediumTower()
{
    loadFromFile("art/Tower/Medium Tower.png");
}

void MediumTower::setScale(float windowHeight)
{
    float scale = windowHeight/sprite.getLocalBounds().height/2.5;
    sprite.setScale(scale,scale);
    setOrigin();

    setHitBox();
}


