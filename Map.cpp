#include "Map.hpp"

Map::Map()
:   battleArea(sf::Vector2f(100,100))
{
    battleArea.setFillColor(sf::Color::Yellow);
    setCenter();
}

void Map::setCenter()
{
    for(int i = 0 ; i<= 3; i++)
    {
        background[i].getSprite().setOrigin(background[i].getSprite().getGlobalBounds().width/2,background[i].getSprite().getGlobalBounds().height/2);
    }
}

sf::FloatRect Map::getRectOfBattleArea()
{
    return battleArea.getGlobalBounds();
}

void Map::setWindowSize(sf::Vector2u size)
{
    for ( int i = 0 ; i<= 3; i++)
    {
        float scale = size.y/background[i].getSprite().getLocalBounds().height;

        if(i == 1|| i==3)
        {
            background[i].getSprite().setScale(-scale,scale);
        }
        else
        {
            background[i].getSprite().setScale(scale,scale);
        }
        battleArea.setSize(sf::Vector2f(background[i].getSprite().getGlobalBounds().width*4, background[i].getSprite().getGlobalBounds().height/1.7));

    }

}

std::vector <sf::Sprite> Map::getSprite()
{
    std::vector <sf::Sprite> v;
    for(int i = 0 ; i<= 3; i++)
    {
        v.push_back(background[i].getSprite());
    }
    return v;
}

void Map::setPosition()
{
    for(int i = 0 ; i<= 3; i++)
    {
        background[i].getSprite().setPosition(i * background[i].getSprite().getGlobalBounds().width,0);
    }
    battleArea.setPosition(background[0].getSprite().getGlobalBounds().left ,background[0].getSprite().getGlobalBounds().top/3);
}


