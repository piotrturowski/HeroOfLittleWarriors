#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef ANIMATEDBACKGROUND_HPP
#define ANIMATEDBACKGROUND_HPP

class AnimatedBackground
{
private:
    sf::RenderTexture renderTexture;
    sf::Texture texture;
    sf::Sprite sprite;
    void createReverseBackground();

public:
    AnimatedBackground();
    void loadImage(sf::String name);
    void setWindowSize(sf::Vector2f windowSize);
    void move();
    sf::Sprite & getSprite();
};
#endif // ANIMATEDBACKGROUND_HPP
