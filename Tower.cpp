#include "Tower.hpp"


Tower::Tower()
{
    range = 10000;
}

void Tower::setPosition(sf::Vector2f pos)
{
    pos.y = pos.y - sprite.getGlobalBounds().height/6;
    sprite.setPosition(pos);
    hitBox.setPosition(pos);
}

void Tower::setHitBox()
{
    hitBox.setSize(sf::Vector2f(sprite.getGlobalBounds().width,sprite.getGlobalBounds().height));
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

void Tower::enemyIsUderTower(sf::Vector2f heroPos)
{
    float distance = phisics::distanceBetweenTwoPoints(heroPos,sprite.getPosition());
    if( distance < range)
    {
        if(magicBall.size()< 3)
            spawnMagicBall();
    }
}

void Tower::spawnMagicBall()
{
    magicBall.push_back(MagicBall());


    magicBall[magicBall.size()-1].getSprite().setPosition(sprite.getPosition().x,sprite.getPosition().y+magicBall.size()*100);

    returnedSprite.push_back(magicBall[magicBall.size()-1].getSprite());
}

std::vector <sf::Sprite> Tower::getMagicBallSprite()
{
    return returnedSprite;
}


