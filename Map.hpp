#ifndef MAP_HPP
#define MAP_HPP
#include <SFML/Graphics.hpp>
#include "Background.hpp"

class Map : public Background
{
protected:
    sf::RectangleShape battleArea;
public:
    Map();
    sf::FloatRect getRectOfBattleArea();
    void setWindowSize(sf::Vector2u size);



};
#endif // MAP_HPP
