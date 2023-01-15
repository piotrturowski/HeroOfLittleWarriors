#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Background
{
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Background();
    void loadBackground(std::string path);
    sf::Sprite & getSprite();
    void setWindowSize(sf::Vector2u size);
};
#endif // BACKGROUND_HPP
