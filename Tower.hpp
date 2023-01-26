#ifndef TOWER_HPP
#define TOWER_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.hpp"


class Tower : public GameObject
{
protected:

public:
    Tower();
    void setHitBox();
    void setPosition(sf::Vector2f pos);
    bool onCollision(sf::FloatRect enemyHitBox);
        sf::RectangleShape hitBox;

};
#endif // TOWER_HPP
