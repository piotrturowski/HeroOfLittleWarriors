#ifndef MAP_HPP
#define MAP_HPP
#include <SFML/Graphics.hpp>
#include "Background.hpp"
#include <iostream>
#include <vector>

class Map
{
protected:
    Background background[4];
    Background grass[4];
    sf::RectangleShape battleArea;
    void setCenter();
public:
    Map();
    sf::FloatRect getRectOfBattleArea();
    void setWindowSize(sf::Vector2u size);
    std::vector <sf::Sprite> getBackgroundSprite();
    std::vector <sf::Sprite> getGrassSprite();
    void setPosition();


};
#endif // MAP_HPP
