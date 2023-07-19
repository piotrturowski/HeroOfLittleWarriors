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
    sf::Font font;
    sf::RenderTexture tex;

    sf::Color unpressedColor;
    sf::Color PressedColor;

    bool blocked;
    sf::Vector2f getTransformedMousePosition(sf::RenderWindow * window);
    bool loadTexture();
    bool mouseIsInside(sf::RenderWindow * window);
    void update(sf::RenderWindow * window);
    void textSetup();
    void textSetupUpdate();
    void swapTexture(int swapingStatus);
   public:

    Button();
    bool isPressed(sf::RenderWindow * window);
    void setNameButton(sf::String name);
    void block();
    void unlock();
    bool isBlocked();
    void setScale(float x);
    sf::Sprite & getSprite();
    sf::Text text;
    void setPosition(float x, float y);

    template <typename T>
    void setPosition(sf::Vector2<T> pos);
};

#endif // BUTTON_HPP
