#include "HitBox.hpp"

void HitBox::hitBoxUpdate()
{
    hitBox.setPosition(sprite.getPosition());
    hitBox.move(-hitBox.getOrigin().x/2*hitBox.getScale().x,hitBox.getOrigin().y*hitBox.getScale().y);
    hitBox.setScale(sprite.getScale());

    weponHitBox.setPosition(sprite.getPosition());

    weponHitBox.move(hitBox.getOrigin().x*hitBox.getScale().x,0);
    weponHitBox.setScale(sprite.getScale());
    weponHitBox.setFillColor(sf::Color::Red);

}
