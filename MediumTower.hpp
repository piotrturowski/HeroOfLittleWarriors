#ifndef MEDIUMTOWER_HPP
#define MEDIUMTOWER_HPP
#include "Tower.hpp"

class MediumTower : public Tower
{

public:
    MediumTower();
    void setScale(float windowHeight);
    void setPosition(sf::Vector2f pos);
};

#endif // MEDIUMTOWER_HPP
