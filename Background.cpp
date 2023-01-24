#include "Background.hpp"

Background::Background()
{
    loadBackground("art/Backgrounds/game_background_2/game_background_2.png");
}

void Background::loadBackground(std::string path)
{
    if(!texture.loadFromFile(path))
    {
        std::cout << "error" << std::endl;
    }
    sprite.setTexture(texture);
}

sf::Sprite & Background::getSprite()
{
   return sprite;
}


