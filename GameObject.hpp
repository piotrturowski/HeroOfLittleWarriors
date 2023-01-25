#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class GameObject
{
protected:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    GameObject();
    bool loadFromFile(std::string path);
    sf::Sprite & getSprite();
};
#endif // GAMEOBJECT_HPP
