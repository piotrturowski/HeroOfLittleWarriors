#include "GameObject.hpp"

GameObject::GameObject()
{

}

bool GameObject::loadFromFile(std::string path)
{
    if(!texture.loadFromFile(path))
    {
        std::cout << "error " << path << "can't load" << std::endl;
        return false;
    }
    sprite.setTexture(texture);
}

sf::Sprite & GameObject::getSprite()
{
    return sprite;
}


