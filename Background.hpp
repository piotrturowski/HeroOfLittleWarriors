#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Background
{
protected:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    Background();
    void loadBackground(std::string path);
    sf::Sprite & getSprite();
};
#endif // BACKGROUND_HPP
