#ifndef CAMERA_HPP
#define CAMERA_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

class Camera
{
    sf::View view;

public:
    void update(sf::Vector2f pos, sf::FloatRect battleArea);
    void setSize(sf::Vector2u size);
    sf::View& getView();

};
#endif // CAMERA_HPP
