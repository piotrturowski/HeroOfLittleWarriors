#include "Animation.hpp"

Animation::Animation()
{
    switchTime = sf::seconds(0);
}

void Animation::setTextureSheet(TextureSheet textureSheet)
{
    ts = textureSheet;
}

void Animation::setSwitchTime(float speed)
{
    switchTime = sf::seconds(speed);
}

void Animation::update(sf::Time deltaTime)
{
    totalTime+=deltaTime;
    if(totalTime > switchTime)
    {
        totalTime-=switchTime;
        ts.nextPositionOfIterator();
    }
}

sf::Texture& Animation::getTexture()
{
    return ts.getCurrentTexture();
}

TextureSheet Animation::getTextureSheet()
{
    return ts;
}
