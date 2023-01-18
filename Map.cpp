#include "Map.hpp"

Map::Map()
:   battleArea(sf::Vector2f(100,100))
{

}



sf::FloatRect Map::getRectOfBattleArea()
{

    return battleArea.getGlobalBounds();
}

void Map::setWindowSize(sf::Vector2u size)
{
    sprite.setScale(size.x/sprite.getLocalBounds().width,size.y/sprite.getLocalBounds().height);
    battleArea.setSize(sf::Vector2f(size.x,size.y/1.7));
    battleArea.setPosition(0,size.y/3.2);
}
