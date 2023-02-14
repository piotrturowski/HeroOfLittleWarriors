#include "Tower.hpp"


Tower::Tower()
{
    range = 200;
    spawnBallTime = sf::seconds(0);
    totalTime = sf::seconds(0);
    spawnCooldown = true;
    magicBallOriginal.loadFromFile("art/Magic balls/Magic ball_1.png");
    magicBallOriginal.getSprite().setOrigin(magicBallOriginal.getSprite().getLocalBounds().width/2,magicBallOriginal.getSprite().getLocalBounds().height/2);

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
        if(magicBall.size() < 3 && spawnCooldown)
        {

            spawnMagicBall();
        }

    }
}

void Tower::spawnMagicBall()
{
    magicBall.push_back(magicBallOriginal);
    magicBall.back().getSprite().setPosition(sprite.getPosition().x,sprite.getPosition().y+magicBall.size()*100);

    std::cout <<"original x = " << magicBallOriginal.getSprite().getOrigin().x <<std::endl;
    std::cout <<"original y = " << magicBallOriginal.getSprite().getOrigin().y <<std::endl;

    std::cout <<magicBall.size()<<" magicball x = " << magicBall[0].getSprite().getOrigin().x <<std::endl;
    std::cout <<magicBall.size()<<" magicball y = " << magicBall[0].getSprite().getOrigin().y <<std::endl;


    spawnCooldown = false;

}

std::vector <sf::Sprite> Tower::getMagicBallSprite()
{
    std::vector <sf::Sprite> returnedSprite;
    for(int i = 0 ; i < magicBall.size(); i++)
    {
        returnedSprite.push_back(magicBall[i].getSprite());
       //std::cout << returnedSprite[0].getOrigin().y <<std::endl;
    }
    return returnedSprite;
}

void Tower::update(sf::Time deltaTime)
{
    for(int i = 0 ; i < magicBall.size(); i++)
    {
        magicBall[i].update(deltaTime);
    }
    checkCooldownIsDown(deltaTime);
}

void Tower::checkCooldownIsDown(sf::Time deltaTime)
{
    totalTime+=deltaTime;
    if(totalTime > spawnBallTime)
    {
        totalTime= sf::seconds(0);
        spawnBallTime = sf::seconds(1);
        spawnCooldown = true;

    }
}


