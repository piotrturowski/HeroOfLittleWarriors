#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef ANIMATEDBACKGROUND_HPP
#define ANIMATEDBACKGROUND_HPP

class AnimatedBackground
{
private:
    sf::RenderTexture renderTexture;
    sf::Texture texture[2];
    sf::Sprite sprite[2];
    sf::Sprite mainSprite;
    void createReverseBackground();
    void connectTwoSprites();
    bool endSprite();
    bool reverseI(int i);
    void swap();

public:
    AnimatedBackground();
    void loadImage(sf::String name);
    void setWindowSize(sf::Vector2f windowSize);
    void move();
    sf::Sprite & getSprite();
    sf::Sprite & getSecondSprite();
};
#endif // ANIMATEDBACKGROUND_HPP
