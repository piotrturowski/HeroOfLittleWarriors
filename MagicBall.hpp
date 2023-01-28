#ifndef MAGICBALL_HPP
#define MAGICBALL_HPP
#include "MagicBall.hpp"
#include "GameObject.hpp"

class MagicBall : public GameObject
{
private:
    sf::Time switchTime;
    sf::Time totalTime;
public:
    MagicBall();
    void update(sf::Time dletaTime);
    void rotate();
    void setSwitchTime(float speed);
};

#endif // MAGICBALL_HPP
