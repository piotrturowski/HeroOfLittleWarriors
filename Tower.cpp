#include "Tower.hpp"

Tower::Tower()
{

}

void Tower::setPosition(sf::Vector2f pos)
{
    sprite.setPosition(pos.x+sprite.getOrigin().x,pos.y);
}


