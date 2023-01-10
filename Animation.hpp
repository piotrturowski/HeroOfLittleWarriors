#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include <iostream>
#include <vector>
#include "textureSheet.hpp"

class Animation
{
    public:
        Animation();
        void setTextureSheet(TextureSheet textureSheet);
        void setSwitchTime(float speed);
        void update(sf::Time deltaTime);
        sf::Texture& getTexture();
    private:
        sf::Time switchTime;
        TextureSheet ts;
        sf::Time totalTime;

};
#endif // ANIMATION_HPP
