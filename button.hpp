#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <SFML/Graphics.hpp>
#include "GameObject.hpp"
#include <queue>
#include <iostream>

class Button
{
    sf::Texture texture[4];
    sf::Sprite sprite;
    sf::String word;
    sf::Font font;
    sf::RenderTexture tex;
    sf::Text text;
    sf::Color unpressedColor;
    sf::Color PressedColor;
    sf::Vector2f getTransformedMousePosition(sf::RenderWindow * window);
    bool loadTexture();
    bool mouseIsInside(sf::RenderWindow * window);
    void update(sf::RenderWindow * window);
    void textSetup();
    void textSetupUpdate();

   public:

    Button();
    bool isPressed(sf::RenderWindow * window);
    void swapTexture(int swapingStatus);
    sf::Sprite & getSprite();

};

#endif // BUTTON_HPP
