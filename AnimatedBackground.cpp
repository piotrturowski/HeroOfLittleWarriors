#include "AnimatedBackground.hpp"

AnimatedBackground::AnimatedBackground()
{

}

void AnimatedBackground::loadImage(sf::String name)
{
    if(!texture[0].loadFromFile(name))
    {
        std::cout << "error can't load Texture " << std::endl;
    }
    createReverseBackground();
}

void AnimatedBackground::createReverseBackground()
{

    sf::Image image = texture[0].copyToImage();
    image.flipHorizontally();

    texture[1].loadFromImage(image);

    for(int i = 0 ; i<2; i++)
        sprite[i].setTexture(texture[i]);

}

sf::Sprite & AnimatedBackground::getSprite()
{
    return sprite[0];
}

sf::Sprite & AnimatedBackground::getSecondSprite()
{
    return sprite[1];
}


void AnimatedBackground::setWindowSize(sf::Vector2f windowSize)
{
    float scale = windowSize.y/sprite[0].getLocalBounds().height;
    for(int i = 0; i<2;i++)
        sprite[i].setScale(scale,scale);

    connectTwoSprites();

}

void AnimatedBackground::connectTwoSprites()
{
    sprite[1].setPosition(sprite[0].getPosition().x + sprite[0].getGlobalBounds().width,sprite[0].getPosition().y);
}

bool AnimatedBackground::endSprite()
{
    for(int i = 0; i<2;i++)
    {
        if(sprite[i].getPosition().x <= -sprite[i].getGlobalBounds().width);
        {

            return true;
        }
    }
    return false;
}

void AnimatedBackground::swap()
{
    for(int i = 0; i<2;i++)
    {
        if(sprite[i].getPosition().x < -sprite[i].getGlobalBounds().width)
        {
            sprite[i].setPosition(sprite[reverseI(i)].getPosition().x+sprite[reverseI(i)].getGlobalBounds().width,0);
        }
    }

}

bool AnimatedBackground::reverseI(int i)
{
    bool j = i;

    return !j;
}

void AnimatedBackground::move()
{
    for(int i = 0; i<2;i++)
    {
        sprite[i].move(-0.5,0);
    }
    if(endSprite())
    {
        swap();
    }
}



