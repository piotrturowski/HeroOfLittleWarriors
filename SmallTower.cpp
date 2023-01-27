#include "SmallTower.hpp"

SmallTower::SmallTower()
{
    loadFromFile("art/Tower/small Tower.png");
}

void SmallTower::setScale(float windowHeight)
{
    float scale = windowHeight/sprite.getLocalBounds().height/3;
    sprite.setScale(scale,scale);
    setOrigin();

    setHitBox();
}


