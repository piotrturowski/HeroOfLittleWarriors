#ifndef SPRITE_HPP
#define SPRITE_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class Sprite
{
public:
    Sprite();
    Sprite(std::string path);
    sf::Sprite &getSprite();
    void setTexture(std::string path);
private:
    sf::Texture Texture;
    public: sf::Sprite sprite;
};
#endif // SPRITE_HPP
