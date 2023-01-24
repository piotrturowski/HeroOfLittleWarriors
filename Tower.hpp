#ifndef TOWER_HPP
#define TOWER_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

class Tower
{
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Tower();
    sf::Sprite & getSprite();
    void setPosition(sf::Vector2f pos);
    void setScale(float windowHeight);
    void loadFromFile(std::string path);

};
#endif // TOWER_HPP
