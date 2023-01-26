#include "SmallTower.hpp"

SmallTower::SmallTower()
{
    loadFromFile("art/Tower/small Tower.png");
}

void SmallTower::setScale(float windowHeight)
{
    float scale = windowHeight/sprite.getLocalBounds().height/3;
    sprite.setScale(scale,scale);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    setHitBox();

}
