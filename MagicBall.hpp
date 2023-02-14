#ifndef MAGICBALL_HPP
#define MAGICBALL_HPP
#include "MagicBall.hpp"
#include "GameObject.hpp"
#include "Phisics.hpp"

class MagicBall : public GameObject
{
private:
    sf::Time switchTime;
    sf::Time totalTime;
    const sf::Vector2f * trackingVector;
    float speed;
public:
    MagicBall();
    void update(sf::Time dletaTime);
    void rotate();
    void moveToTarget();
    void setSwitchTime(float speed);
    void setVectorTracking(const sf::Vector2f * trackingVector );

};

#endif // MAGICBALL_HPP
