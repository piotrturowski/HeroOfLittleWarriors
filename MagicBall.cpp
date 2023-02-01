#include "MagicBall.hpp"

MagicBall::MagicBall()
{
    texture.setSmooth(true);
    loadFromFile("art/Magic balls/Magic ball_1.png");

    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    sprite.setScale(0.05,0.05);
    totalTime = sf::seconds(0);
    switchTime = sf::seconds(0);
}

void MagicBall::update(sf::Time deltaTime)
{
    totalTime+=deltaTime;
    if(totalTime > switchTime)
    {
        totalTime-=switchTime;
        rotate();
    }
}

void MagicBall::rotate()
{
    sprite.rotate(sprite.getRotation()+1);
}

void MagicBall::setSwitchTime(float speed)
{
    switchTime = sf::seconds(speed);
}