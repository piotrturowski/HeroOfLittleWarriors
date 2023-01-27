#include "Tower.hpp"

Tower::Tower()
{

}

void Tower::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos);
    hitBox.setPosition(pos);
}

void Tower::setHitBox()
{
    hitBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width,sprite.getGlobalBounds().height));
    hitBox.Transformable(sprite.getTransform());
    setOrigin();
    hitBox.setPosition(sprite.getPosition());
    //std::cout << sprite.getOrigin().y << std::endl;

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


void Tower::setOrigin()
{
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    hitBox.setOrigin(hitBox.getLocalBounds().width/2,hitBox.getLocalBounds().height/2);
}
