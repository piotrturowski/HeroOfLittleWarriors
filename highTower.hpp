#ifndef HIGHTOWER_HPP
#define HIGHTOWER_HPP
#include "GameObject.hpp"

class HighTower : public GameObject
{

public:

    void setScale(float windowHeight);
    void setPosition(sf::Vector2f pos);
};

#endif // HIGHTTOWER_HPP
