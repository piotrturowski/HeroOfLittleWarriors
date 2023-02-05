#include "Tower.hpp"


Tower::Tower()
{
    range = 200;
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
    std::cout << distance <<std::endl;
}

void Tower::spawnMagicBall()
{
    magicBall.push_back(MagicBall());
    for(int i = 0; i<magicBall.size();i++)
    {
        magicBall[i].loadFromFile("art/Magic balls/Magic ball_1.png");
        magicBall[magicBall.size()-1].getSprite().setPosition(sprite.getPosition().x,sprite.getPosition().y+magicBall.size()*100);
    }

}

std::vector <sf::Sprite> Tower::getMagicBallSprite()
{
    std::vector <sf::Sprite> rs;
    for(int i = 0 ; i < magicBall.size(); i++)
    {
        rs.push_back(magicBall[i].getSprite());
    }
    return rs;
}


