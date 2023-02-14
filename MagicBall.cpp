#include "MagicBall.hpp"

MagicBall::MagicBall()
{
    texture.setSmooth(true);
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
    sprite.rotate(10);
}

void MagicBall::setSwitchTime(float speed)
{
    switchTime = sf::seconds(speed);
}

void MagicBall::setVectorTracking(const sf::Vector2f * trackingVector )
{
    this->trackingVector = trackingVector;
}


