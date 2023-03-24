#ifndef MAP_HPP
#define MAP_HPP
#include <SFML/Graphics.hpp>
#include "Background.hpp"
#include <iostream>
#include <vector>
#include "Base.hpp"
#include "SmallTower.hpp"
#include "MediumTower.hpp"

class Map
{
protected:
    Base base;
    SmallTower smallTower;
    MediumTower mediumTower;
    Background background[4];
    Background grass[4];
    sf::RectangleShape battleArea;
    void setCenter();
    void setObjectPosition();
public:
    Map();
    Base * getBase();
    SmallTower * getSmallTower();
    MediumTower * getMediumTower();
    void setup();
    sf::FloatRect getRectOfBattleArea();
    void setWindowSize(sf::Vector2u size);
    std::vector <sf::Sprite> getBackgroundSprite();
    std::vector <sf::Sprite> getGrassSprite();
    void setScale(unsigned int windowHeigh);
    void setPosition();



};
#endif // MAP_HPP
