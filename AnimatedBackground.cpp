#include "AnimatedBackground.hpp"

AnimatedBackground::AnimatedBackground()
{

}

void AnimatedBackground::loadImage(sf::String name)
{
    if(!texture.loadFromFile(name))
    {
        std::cout << "error can't load Texture " << std::endl;
    }
    createReverseBackground();
}

void AnimatedBackground::createReverseBackground()
{
    renderTexture.create(texture.getSize().x*2,texture.getSize().y);
    renderTexture.clear(sf::Color::Transparent);

    sf::Sprite sprite(texture);

    renderTexture.draw(sprite);

    sf::Image image = texture.copyToImage();

    image.flipHorizontally();

    texture.loadFromImage(image);
    sprite.setTexture(texture);

    sprite.setPosition(sprite.getGlobalBounds().width,0);

    renderTexture.draw(sprite);

    renderTexture.display();
    this->sprite.setTexture(renderTexture.getTexture());
}

sf::Sprite & AnimatedBackground::getSprite()
{
    return sprite;
}


void AnimatedBackground::setWindowSize(sf::Vector2f windowSize)
{
    float scale = windowSize.y/sprite.getLocalBounds().height;
    sprite.setScale(scale,scale);
}

void AnimatedBackground::move()
{
    sprite.move(-1,0);
}

