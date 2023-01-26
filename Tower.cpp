#include "Tower.hpp"

Tower::Tower()
{

}

void Tower::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos.x+sprite.getOrigin().x,pos.y);
    hitBox.setPosition(pos.x+sprite.getOrigin().x,pos.y);
}

void Tower::setHitBox()
{
    hitBox.setOrigin(sprite.getOrigin());
    hitBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width,sprite.getGlobalBounds().height));
    hitBox.setPosition(sprite.getPosition());
    std::cout << sprite.getPosition().x;

}

bool Tower::onCollision(sf::FloatRect enemyHitBox)
{
    if(hitBox.getGlobalBounds().intersects(enemyHitBox))
    {
         //std::cout << "is Collsion" << std::endl;
         return true;
    }
    else
    {
        //std::cout << "not is Collsion" << std::endl;
        return false;


    }
}

