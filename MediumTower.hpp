#ifndef MEDIUMTOWER_HPP
#define MEDIUMTOWER_HPP
#include "GameObject.hpp"

class MediumTower : public GameObject
{

public:
    MediumTower();
    void setScale(float windowHeight);
    void setPosition(sf::Vector2f pos);
};

#endif // MEDIUMTOWER_HPP
