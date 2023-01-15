#include "Background.hpp"

Background::Background()
{
    loadBackground("art/Backgrounds/game_background_2/game_background_2.png");
}

void Background::loadBackground(std::string path)
{
    texture.loadFromFile(path);
    sprite.setTexture(texture);
}

sf::Sprite & Background::getSprite()
{
   return sprite;
}

void Background::setWindowSize(sf::Vector2u size)
{
    sprite.setScale(size.x/sprite.getLocalBounds().width,size.y/sprite.getLocalBounds().height);

}

