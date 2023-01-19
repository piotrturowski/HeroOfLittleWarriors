#include "Map.hpp"

Map::Map()
:   battleArea(sf::Vector2f(100,100))
{
    battleArea.setFillColor(sf::Color::Yellow);
}



sf::FloatRect Map::getRectOfBattleArea()
{

    return battleArea.getGlobalBounds();
}

void Map::setWindowSize(sf::Vector2u size)
{
    float scale = size.y/sprite.getLocalBounds().height;
    sprite.setScale(scale,scale);
    battleArea.setSize(sf::Vector2f(sprite.getGlobalBounds().width,sprite.getGlobalBounds().height/1.7));
    battleArea.setPosition(0,size.y/3);
}


