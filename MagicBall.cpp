#include "MagicBall.hpp"

MagicBall::MagicBall()
{
    texture.setSmooth(true);
    sprite.setScale(0.05,0.05);
    totalTime = sf::seconds(0);
    switchTime = sf::seconds(0);
    speed = 5;
}

void MagicBall::update(sf::Time deltaTime)
{
    totalTime+=deltaTime;
    if(totalTime > switchTime)
    {
        totalTime-=switchTime;
        rotate();
        moveToTarget();
    }

}


void MagicBall::moveToTarget()
{
    if(getDistanceToTarget() < 50)
    {
        //std::cout << "in target" << std::endl;

    }
    else
    {
        sf::Vector2f acceleration(0,0);
        if(trackingVector->y > sprite.getPosition().y)
        {
            acceleration.y = 1;
        }
        if(trackingVector->y < sprite.getPosition().y)
        {
            acceleration.y = -1;
        }
        if(trackingVector->x > sprite.getPosition().x)
        {
            acceleration.x = 1;
        }
        if(trackingVector->x < sprite.getPosition().x)
        {
            acceleration.x = -1;
        }
        acceleration.x = acceleration.x*speed;
        acceleration.y= acceleration.y*speed;
        sprite.move(acceleration);
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

void MagicBall::setTrackingVector(const sf::Vector2f * trackingVector )
{
    this->trackingVector = trackingVector;
}

float MagicBall::getDistanceToTarget()
{
    return phisics::distanceBetweenTwoPoints(*trackingVector,sprite.getPosition());
}

bool MagicBall::onCollision(sf::FloatRect enemyHitBox)
{
    if(sprite.getGlobalBounds().intersects(enemyHitBox))
    {
         //std::cout << "is Collsion" << std::endl;
         return true;
    }
        return false;
}

