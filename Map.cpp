#include "Map.hpp"

Map::Map()
:   battleArea(sf::Vector2f(100,100))
{
    for(int i = 0; i <4 ; i++)
    {
        grass[i].loadBackground("art/Backgrounds/game_background_2/layers/front_decor.png");

    }
    battleArea.setFillColor(sf::Color::Yellow);
    setCenter();


}

void Map::setCenter()
{
    for(int i = 0 ; i<= 3; i++)
    {
        background[i].getSprite().setOrigin(background[i].getSprite().getGlobalBounds().width/2,background[i].getSprite().getGlobalBounds().height/2);
        grass[i].getSprite().setOrigin(grass[i].getSprite().getGlobalBounds().width/2, grass[i].getSprite().getGlobalBounds().height/2);
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
            grass[i].getSprite().setScale(-scale,scale);
        }
        else
        {
            background[i].getSprite().setScale(scale,scale);
            grass[i].getSprite().setScale(scale,scale);
        }
        battleArea.setSize(sf::Vector2f(background[i].getSprite().getGlobalBounds().width*4, background[i].getSprite().getGlobalBounds().height/1.7));

    }

}

std::vector <sf::Sprite> Map::getBackgroundSprite()
{
    std::vector <sf::Sprite> backgroundSprite;
    for(int i = 0 ; i<= 3; i++)
    {
        backgroundSprite.push_back(background[i].getSprite());
    }
    return backgroundSprite;
}


std::vector <sf::Sprite> Map::getGrassSprite()
{
    std::vector <sf::Sprite> grassSprite;
    for(int i = 0 ; i<= 3; i++)
    {
        grassSprite.push_back(grass[i].getSprite());
    }
    return grassSprite;
}

void Map::setPosition()
{
    for(int i = 0 ; i<= 3; i++)
    {
        background[i].getSprite().setPosition(i * background[i].getSprite().getGlobalBounds().width,0);
        grass[i].getSprite().setPosition(i * grass[i].getSprite().getGlobalBounds().width,0);
    }
    battleArea.setPosition(background[0].getSprite().getGlobalBounds().left ,background[0].getSprite().getGlobalBounds().top/3);
}


