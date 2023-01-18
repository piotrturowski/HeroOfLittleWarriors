#ifndef MAP_HPP
#define MAP_HPP
#include <SFML/Graphics.hpp>
#include "Background.hpp"

class Map : public Background
{

public:
    Map();
    sf::FloatRect getRectOfBattleArea();
    void setWindowSize(sf::Vector2u size);
        sf::RectangleShape battleArea;


};
#endif // MAP_HPP
