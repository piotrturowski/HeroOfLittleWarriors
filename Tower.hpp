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
    void setPosition(sf::Vector2f pos);

};
#endif // TOWER_HPP
