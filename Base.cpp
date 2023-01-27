#include "Base.hpp"

Base::Base()
{
    loadFromFile("art/Base/Base.png");
}

void Base::setScale(float windowHeight)
{
    float scale = windowHeight/sprite.getLocalBounds().height*0.90;
    sprite.setScale(-scale,scale);
    setOrigin();
    setHitBox();
}


