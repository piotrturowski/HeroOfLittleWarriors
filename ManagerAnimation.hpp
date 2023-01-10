#ifndef MANAGERANIMATION_HPP
#define MANAGERANIMATION_HPP
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "Animation.hpp"

class ManagerAnimation
{
public:
    ManagerAnimation();
    void swapAnimation(std::string name);
    void addAnimation(Animation anim, std::string animationName);
    sf::Texture & getTexture();
    void update(sf::Time deltaTime);
    void setSpeedCurrentAnimation(float seconds);
private:
    short currentAnimation;
    std::vector <Animation> animationSheet;
    std::vector <std::string> animationName;

};
#endif // MANAGERANIMATION_HPP
